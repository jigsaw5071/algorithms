#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/** =================== JOB SEQUENCING PROBLEM ==================================
=> This is another very interesting problem based on greedy paradigm.
=> This problem can be done in both ways i.e. either by decreasingly sorting by Profit or decreasingly sorting 
by Deadline.
=> This problem is implemented in deadline sorted way.
=> You can find the solution to Profit sorted way at : http://www.geeksforgeeks.org/job-sequencing-problem-set-1-greedy-algorithm/
=> Both the solutions take O(n * n) time
=> There is a better algorithm for this using union-find DS . You can take a look at it in Disjoint -Set directory of this
repo.
*/

struct Job{
  char name;
  int deadline;
  int profit;
};

int main(void){
  vector<Job> jobs = { {'a', 3, 25}, {'b', 3, 20}, {'c', 2, 24},{'d', 2, 28}, {'e', 1, 22}};
  sort(jobs.begin() , jobs.end() , [](Job& x , Job& y){
    return ((x.deadline == y.deadline)?(x.profit > y.profit):(x.deadline > y.deadline));
  });
  int maxDeadLine = jobs[0].deadline;
  vector<Job> ans(maxDeadLine + 1);
  vector<bool> isEmpty(maxDeadLine + 1 , true);
  isEmpty[maxDeadLine] = false;
  ans[maxDeadLine] = jobs[0];
  for(int i = 1 ; i < jobs.size() ; ++i){
    int deadline = jobs[i].deadline;
    if(isEmpty[deadline]){
      isEmpty[deadline] = false;
      ans[deadline] = jobs[i];
    }
    else{
      while(deadline > 0){
        
        if(isEmpty[deadline]){
          ans[deadline] = jobs[i];
          isEmpty[deadline] = false;
          break;
        }
        if(jobs[i].profit > ans[deadline].profit){
          int j = deadline - 1;
          Job jb = ans[deadline];
          ans[deadline] = jobs[i];
          while(j > 0 || !isEmpty[j]){
            Job temp = ans[j];
            ans[j] = jb;
            jb = temp;
            j--;
          }
          if(j > 0 && isEmpty[j]){
            ans[j] = jb;
            isEmpty[j] = false;
          }
          break;
        }
        deadline--;
      }
    }
  }
  
  for(int i = 1 ; i <= maxDeadLine ; ++i){
    cout << ans[i].name << " ";
  }
  
  return 0;
}
