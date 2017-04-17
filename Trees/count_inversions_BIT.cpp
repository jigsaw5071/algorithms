/**
@ Shub/ham Sharma
Date:18/04/2017
Ref: http://www.geeksforgeeks.org/count-inversions-array-set-3-using-bit/
*/

#include<bits/stdc++.h>
using namespace std;

int BIT[10000];

void update(int idx,int val,const int N){
  while(idx<=N){
    BIT[idx]+=val;
    idx+=(idx & -idx);
  }
}

int query_sum(int idx){
  int sum=0;
  while(idx>0){
    sum+=BIT[idx];
    idx = idx - (idx & -idx);
  }
}

void convert_arr(int* arr,const int n){
  vector<int> temp(arr,arr+n);
  sort(temp.begin(),temp.end());
  
  
  for(int i=0;i<n;i++){
    arr[i]=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin() +1;
  }
  
}

int count_inversions(int* arr,const int n){
  convert_arr(arr,n);
  memset(BIT,0,sizeof(BIT));
  int result=0;
  for(int i=n-1;i>=0;i--){
    result+=query_sum(arr[i-1]);
    update(arr[i],1,n);
  }
  return result;
}

int main(void){
  int arr[]={8,5,4,6,3};
  int n=sizeof(arr)/sizeof(arr[0]);
  printf("%d\n",count_inversions(arr,n));
  
}
