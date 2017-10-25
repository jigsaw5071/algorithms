#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/** =================== JOB SEQUENCING PROBLEM ==================================
=> The time complexity of this algorithm is O(nlogn)
*/

struct Job{
  char name;
  int deadline;
  int profit;
};

class DisjointSet{
  public:
  int* par;
  DisjointSet(const int n){
    par = new int[n + 1];
    for(int i = 0 ; i <= n ; ++i)par[i] = i;
  }
  ~DisjointSet(){
    delete [] par;
  }
  
  int find(const int x){
    if(x == par[x])return x;
    par[x] = find(par[x]);
    return par[x];
  }
  
  void merge(const int x , const int y){
    par[y] = x;
  }
  
  
};

int main(void){
  vector<Job> jobs = { { 'a', 2, 100 }, { 'b', 1, 19 },  { 'c', 2, 27 },  { 'd', 1, 25 }, { 'e', 3, 15 } };
  sort(jobs.begin() , jobs.end() , [](Job& x , Job& y){
    return x.profit > y.profit;
  });
  int maxDeadLine = 0;
  for(auto& job : jobs)maxDeadLine = max(maxDeadLine , job.deadline);
  DisjointSet disjointSet(maxDeadLine) ;
  vector<Job> ans;
  for(auto& job : jobs){
    int availableSlot = disjointSet.find(job.deadline);
    if(availableSlot > 0){
      ans.push_back(job);
      disjointSet.merge(disjointSet.find(availableSlot - 1) , availableSlot);
    }
  }
  
  for(auto& job : ans){
    cout << job.name << " ";
  }
  
  return 0;
}
