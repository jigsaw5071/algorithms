/**
@ Shubham Sharma
Date:20/04/2017
*/
/**=============Count Inversion using Segment Tree====================================
1. the time complexity is O(logn)
2. the space complexity is O(4*n)
*/

#include<bits/stdc++.h>
using namespace std;

int ST[8*2000004];
int arr[200004];
uint64_t result;

void update(const int l,const int r,const int pos,const int key,const int value){
  if(key<l || key>r){return;}
  if(l==r){
    ST[pos]+=value;
    return;
  }
  int mid=(l+r)>>1;
  update(l,mid,2*pos+1,key,value);
  update(mid+1,r,2*pos+2,key,value);
  ST[pos]=ST[2*pos+1]+ST[2*pos+2];
}

uint64_t query_sum(const int ql,const int qr,const int l,const int r,const int pos){
  if(ql>r || qr<l){return 0;}
  if(ql<=l && r<=qr){
    return ST[pos];
  }
  int mid=(l+r)>>1;
  return query_sum(ql,qr,l,mid,2*pos+1) +query_sum(ql,qr,mid+1,r,2*pos+2);
}

void convert_tree(const int n){
  vector<int> temp(arr,arr+n);
  sort(temp.begin(),temp.end());
  for(int i=0;i<n;i++){
    arr[i]=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin()+1;
  }
}

void count_inversions(const int n){
  convert_tree(n);
  for(int i=n-1;i>=0;i--){
    result+=query_sum(1,arr[i]-1,1,n,1);
    update(1,n,1,arr[i],1);
  }
}

int main(void){
  cin.tie(NULL);ios_base::sync_with_stdio(false);
  int T;cin>>T;
  while(T--){
    int n;
    cin>>n;
    for(int i=0;i<5*n;i++){ST[i]=0;}
    result=0;
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    count_inversions(n);
    cout<<result<<endl;
  }
  return 0;
}

