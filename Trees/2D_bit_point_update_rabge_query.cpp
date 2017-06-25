/**
author : Shubham Sharma
Date : 25/06/2017
Ref : https://www.quora.com/How-do-I-implement-a-2D-binary-indexed-tree-for-range-update-and-range-query-operations

They can be used in excel range update and range queries as well

"The only hinderance in your path is your thinking . -  Ratan Tata"
*/

#include<bits/stdc++.h>
using namespace std;

#define R 26
#define C 26

int BIT[R+1][C+1];

void init(){
  for(int i=0;i<=R;++i){
    for(int j = 0;j<=C;++j){
      BIT[i][j] = 0;
    }
  }
}

void update(int x,int y,const int val){
  
  int y1;
  
  while(x <= R){
    
    y1 = y;
    while(y1 <= C){
      BIT[x][y1]+=val;
      y1 +=(y1 & -y1);
    }
   x += (x & -x); 
  }
  
}

int query(int x,int y){
  int y1 = y;
  int sum = 0;
  while(x > 0){
    y1 = y;
    while(y1 > 0){
      sum+=BIT[x][y1];
      y1 -= (y1 & -y1);
    }
    x -= (x & -x);
  }
  return sum;
}

int read_range(const int si,const int sj,const int ei,const int ej){
  
  return query(ei,ej) - query(ei,sj-1) - query(si-1,ej) + query(si-1,sj-1);
}


int main(void){
  
  init();
  
  update(1,2,3);
  update(1,3,4);
  cout<<read_range(1,1,2,3);
  
  return 0;
}
