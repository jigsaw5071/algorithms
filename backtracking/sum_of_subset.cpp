/**
@ Shubham Sharma
Date: 28/03/2017
*/

/**============================ SUBSET OF SUM USING BACKTRACKING========================================
 1. The time complexity is exponential.
 2. Several pruning optimizations are applied.

*/

#include<iostream>
#include<algorithm>
using namespace std;

bool is_valid(int* w,const int n,const int i,const int wt,const int total,const int sum){
  
  return ((i+1<n) && (wt+total >= sum) && (wt==sum || wt+w[i+1]<=sum));
  
}

void print_sol(int* w,int *x,const int k){
  for(int i=0;i<=k;++i){
    if(x[i]==1){
      cout<<w[i]<<" ";
    }
  }
  cout<<endl;
}

void sum_of_subset(int* w,int* x,const int n,const int i,const int wt,const int total,const int sum){
  
  if(is_valid(w,n,i,wt,total,sum)){
    if(wt==sum){
      print_sol(w,x,i);
    }
    else{
      x[i+1]=1;
      sum_of_subset(w,x,n,i+1,wt+w[i+1],total-w[i+1],sum);
      x[i+1]=0;
      sum_of_subset(w,x,n,i+1,wt,total-w[i+1],sum);
    }
  }
  
}


int main(void){
  int w[]={15, 22, 14, 26, 32, 9, 16, 8};
  int sum=53;
  int n=sizeof(w)/sizeof(w[0]);
  sort(w,w+n);
  int *x=new int[n];
  int total=0;
  for(int i=0;i<n;++i){total+=w[i];}
  int wt=0;
  sum_of_subset(w,x,n,-1,wt,total,sum);
  return 0;
}
