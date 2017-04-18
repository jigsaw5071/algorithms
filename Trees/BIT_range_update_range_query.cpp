/**
@ shubham sharma
Date: 18/04/2017
Ref:https://kartikkukreja.wordpress.com/2013/12/02/range-updates-with-bit-fenwick-tree/
*/

#include<bits/stdc++.h>

using namespace std;



void update(vector<int>& BIT,int idx,const int val,const int MAX){
  for(;idx<=MAX;idx+=(idx & -idx)){
    BIT[idx]+=val;
  }
}

int query(vector<int>& BIT,int idx){
  int sum=0;
  for(;idx>0;idx-=(idx & -idx)){
    sum+=BIT[idx];
  }
  return sum;
}

int range_query(vector<int>& BIT1,vector<int>& BIT2,const int l,const int r){
  //we need Sum[1:::r] - Sum[1:::l-1]
  int sum_1_r=r*query(BIT1,r)-query(BIT2,r);
  int sum_1_l=l*query(BIT1,l)-query(BIT2,l);
  return sum_1_r-sum_1_l;
}


void update_range(vector<int>& BIT1,vector<int>& BIT2,const int l,const int r,const int val){
  update(BIT1,l,val,BIT1.size());
  update(BIT1,r+1,-val,BIT1.size());
  update(BIT2,l,(l-1)*val,BIT2.size());
  update(BIT2,r+1,-1*val*r,BIT2.size());
}

int main(void){
  const int MAX_RANGE=20;
  vector<int> BIT1(MAX_RANGE+1,0),BIT2(MAX_RANGE+1,0);
  update_range(BIT1,BIT2,1,4,5);
  update_range(BIT1,BIT2,3,6,3);
  cout<<range_query(BIT1,BIT2,3,4);
  return 0;
}
