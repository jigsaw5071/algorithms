/**
@Shubham Sharma
*/

/**=====================N Queens Problem====================================
 1. This is the generalized paradigm of the backtracking.
 2. The time complexity of this algorithm is exponential
 3. The space complexity is O(n)

**/
#include<iostream>
#include<vector>
using namespace std;

bool solve_N_Queens_one_solution_util(const int N,const int row,vector<int>& position){
  if(N==row){
    for(int i=0;i<N;++i){
      for(int j=0;j<N;++j){
        if(j==position[i]){
          cout<<1<<" ";
        }
        else{
          cout<<0<<" ";
        }
      }
      cout<<endl;
    }
    
    return true;
  }
  for(int col=0;col<N;++col){
    bool is_safe=true;
    for(int i=0;i<row;++i){
      
      // check for safeness
      if(col==position[i] || (i-position[i] == row-col) || (i+position[i] == row+col)){
        is_safe=false;
        break;
      }
      
    }
    
    if(is_safe){
      position[row]=col;
      if(solve_N_Queens_one_solution_util(N,row+1,position)){
        return true;
      }
    }
    
    
  }
  return false;
}

bool solve_N_Queens_one_solution(const int N){
  vector<int> position(N,-1);//it contains the col of the present element where row 
  return solve_N_Queens_one_solution_util(N,0,position);
}

int main(void){
  int N=4;
  if(solve_N_Queens_one_solution(N)){
    cout<<"Possible"<<endl;
  }
  else{
    cout<<"Not Possible"<<endl;
  }
  return 0;
}
