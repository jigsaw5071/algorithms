/**
@ Shubham Sharma
*/

/**====== SUDOKU USING BACKTRACKING SOLUTION

*/

#include<bits/stdc++.h>
using namespace std;
int row_hash[10][10];
int col_hash[10][10];
int arr[10][10];

void init_start(){
  for(int i=0;i<=9;i++){
    for(int j=0;j<=9;j++){
      row_hash[i][j]=0;
      col_hash[i][j]=0;
    }
  }
}

bool all_full(){
  for(int i=1;i<=9;i++){
    for(int j=1;j<=9;j++){
      if(arr[i][j]==0){
        return false;
      }
    }
  }
  return true;
}

void print_sol(){
  for(int i=1;i<=9;++i){
    for(int j=1;j<=9;++j){
      cout<<arr[i][j]<<" ";
    }
  }
}

pair<int,int> get_empty_slot(){
  for(int i=1;i<=9;i++){
    for(int j=1;j<=9;j++){
      if(arr[i][j]==0){
        return make_pair(i,j);
      }
    }
  }
}

bool is_block_safe(const int row,const int col,int num){
 int i,j;
 if(row>=1 && row<=3){
   i=1;
 }
 else if(row>=4 && row<=6){
   i=4;
 }
 else if(row>=7 && row<=9){
   i=7;
 }
 
 if(col>=1 && col<=3){
   j=1;
 }
 else if(col>=4 && col<=6){
   j=4;
 }
 else if(col>=7 && col<=9){
   j=7;
 }
 for(int x=i;x<i+3;x++){
   for(int y=j;y<j+3;y++){
     if(arr[x][y]==num){
       return false;
     }
   }
 }
 return true;
}

bool solve_sudoku(){
  if(all_full()){
    print_sol();
    return true;
  }
  pair<int,int> temp=get_empty_slot();
  int row=temp.first;
  int col=temp.second;
  for(int i=1;i<=9;i++){
    if(row_hash[row][i]==0 && col_hash[col][i]==0 && is_block_safe(row,col,i)){
      row_hash[row][i]=1;
      col_hash[col][i]=1;
      arr[row][col]=i;
      if(solve_sudoku()){
        return true;
      }
      row_hash[row][i]=0;
      col_hash[col][i]=0;
      arr[row][col]=0;
    }
  }
  return false;
}

int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int T;
  cin>>T;
  while(T--){
    init_start();
    for(int i=1;i<=9;++i){
      for(int j=1;j<=9;++j){
        int x;
        cin>>x;
        arr[i][j]=x;
        if(x>0){
          row_hash[i][x]=1;
          col_hash[j][x]=1;
        }
      }
    }
    solve_sudoku();
  }
  return 0;
}
