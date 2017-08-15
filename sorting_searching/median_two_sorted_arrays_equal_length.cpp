/**
author : Shubham Sharma
Date : 16/08/2017
Ref: http://www.geeksforgeeks.org/median-of-two-sorted-arrays/
*/

/** ========== MEDIAN OF TWO SORTED ARRAYS WHEN BOTH OF THEM HAVE EQUAL LENGTH

=> The time complexity is O(logn)

*/

#include<bits/stdc++.h>
using namespace std;

double median2(const int a,const int b){
  double ans = ((double)a + (double)b)/2.0;
}

double median4(const int a,const int b,const int c,const int d){
  double ans = a + b  + c + d - max(max(a,b),max(c,d)) - min(min(a,b),min(c,d)); ans /= 2.0; return ans;
}

double findMedianUtil(vector<int>& A,vector<int>& B,const int startA,const int startB ,const int n){
  if(n == 0)return 0.0;
  
  if(n == 1)return median2(A[startA],B[startB]);
  
  if(n == 2)return median4(A[startA],A[startA+1],B[startB],B[startB+1]);
  
  int idx = (n-1)/2;
  
  if(A[startA + idx] <= B[startB + idx]){
    return findMedianUtil(A,B,startA + idx,startB,n/2+1);
  }
  return findMedianUtil(A,B,startA,startB + idx,n/2+1);
  
}

int main(void){
  vector<int> A = {1,2,3,8};
  vector<int> B = {5,6,7,8};
  cout<<findMedianUtil(A,B,0,0,A.size());
  return 0;
}
