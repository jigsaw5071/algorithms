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
 5. This is the algorithm paradigm of point update and Range queries
*/

#include<iostream>
#include<string.h>
using namespace std;

int BIT[10000];


// Single Point Update Method in Bit
void update_point(int idx,const int value,const int MAX_VAL){
  while(idx <= MAX_VAL){
    BIT[idx]+=value;
    idx+=( idx & -idx);// next element
  }
}

//Range Sum Read
int read_range(int idx){
  int sum=0;
  while(idx > 0){
    sum+=BIT[idx];
    idx-=(idx & -idx);
  }
  return sum;
}

void create_BIT(int *arr,const int MAX_VAL){
   for(int i=1;i<=MAX_VAL;i++){
     update_point(i,arr[i-1],MAX_VAL);
   }
}


int main(void){
  memset(BIT,0,sizeof(BIT));
  int arr[]={3,2,-1,6,5,4,-3,3,7,2,3};
  const int MAX_VAL=sizeof(arr)/sizeof(arr[0]);
  create_BIT(arr,MAX_VAL);
  
  
  return 0;
}
