/**
author : Shubham Sharma
Date : 16/08/2017
*/

/**==== FINDING THE MEDIAN OF TWO SORTED ARRAYS USING KTH SMALLEST ELEMENT =============

=> The time complexity of the above algorithm is O(logn + logm)

*/
#include<bits/stdc++.h>
using namespace std;

int findKth(vector<int>& A,const int lA,const int rA,vector<int>& B,const int lB,const int rB,const int k){
  
  if(lA > rA && lB > rB)return 0;
  if(lA > rA)return B[lB + k-1];
  if(lB > rB)return A[lA + k - 1];
  
  int midA = lA + (rA - lA)/2; int midB = lB + (rB - lB)/2;
  
  if(k <= (midB - lB) + (midA - lA) + 1){
    if(A[midA] <= B[midB])return findKth(A,lA,rA,B,lB,midB - 1, k);
    else return findKth(A,lA,midA - 1,B,lB,rB,k);
  }
  else{
    if(A[midA] <= B[midB])return findKth(A,midA + 1, rA,B,lB,rB,k - (midA - lA) - 1);
    else return findKth(A,lA,rA,B,midB + 1, rB,k - (midB - lB) - 1);
  }
  
  
}

int main(void){
  vector<int> nums1 = {1,2,3,4};
  vector<int> nums2 = {5,5,6,7};
  int n = nums1.size(); int m = nums2.size();
        
  double ans ;
  int len = n+m;
  
  ans = findKth(nums1,0,nums1.size() - 1,nums2,0,nums2.size() - 1,(len-1)/2 + 1);
  
  if(len%2 == 0){
    ans = (ans + findKth(nums1,0,nums1.size() - 1,nums2,0,nums2.size() - 1,(len-1)/2 + 2 ))/2.0;
  }
  cout<<ans<<endl;
  return 0;
}
