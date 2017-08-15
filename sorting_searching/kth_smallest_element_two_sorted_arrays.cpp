/**
author : Shubham Sharma
Date : 16/08/2017
Ref: https://discuss.leetcode.com/topic/5728/share-one-divide-and-conquer-o-log-m-n-method-with-clear-description/10
*/

/**===========FINDING THE KTH SMALLEST ELEMENT IN A SORTED ARRAY===============

=> Time complexity is O(logm + logn)
*/

#include<bits/stdc++.h>
using namespace std;


int findKth(vector<int>& A,const int lA,const int rA,vector<int>& B,const int lB,const int rB,const int k){
  if(lA > rA && lB > rB)return 0;
  if(lA > rA)return B[lB + k - 1];
  if(lB > rB)return A[lA + k - 1];
  
  int midA = lA + (rA - lA)/2; int midB = lB + (rB - lB)/2;
  
  if(k <= ((midA - lA) + (midB - lB) + 1)){
    if(A[midA] <= B[midB]) return findKth(A,lA,rA,B,lB,midB-1,k);
    else return findKth(A,lA,midA-1,B,lB,rB,k);
  }
  else{
    if(A[midA] <= B[midB]) return findKth(A,midA+1,rA,B,lB,rB,k-(midA - lA) -1);
    else return findKth(A,lA,rA,B,midB + 1,rB, k - (midB - lB) - 1);
  }
  
}

int main(void){
  vector<int> A = {1,2,3,5};
  vector<int> B = {3,5,7,9};
  int k = 7;
  cout<<findKth(A,0,A.size() - 1,B,0,B.size()-1,k);
  return 0;
}
