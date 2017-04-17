/**
@Shubham Sharma
Date: 17/04/2017
Ref:https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/
*/

/**=====================binary-indexed-trees===============================================
 1. They are better than segment trees as they take less space O(n) as compared to segment trees o(4*n).
 2. They are a lot easier to code.
 3. The worst case time complexity in updation and query is O(logn)
 4. The time complexity to convert an array to binary-indexed-tree is O(N log N)
 5. This is the algorithm paradigm of update range and point queries
*/

#include<iostream>
#include<string.h>
using namespace std;

int BIT[10000];
int N;

void update(int idx,const int val){
  while(idx<=N){
    BIT[idx]+=val;
    idx=idx+ (idx & -idx);
  }
}

void update_range(const int l,const int r,const int val){
  update(l,val);
  update(r+1,-val);
}

int point_query(int idx){
  int sum=0;
  for(;idx>0;idx-=(idx & -idx)){
     sum+=BIT[idx];
     
  }
     
  return sum;   
}

void print_BIT(){
  for(int i=1;i<=N;i++){
    cout<<i<<" :"<<BIT[i]<<endl;
  }
}

int main(void){
  memset(BIT,0,sizeof(BIT));
  N=11;
  update_range(3,4,2);
  
  update_range(4,6,3);
  print_BIT();
  cout<<point_query(7);
  return 0;
}
