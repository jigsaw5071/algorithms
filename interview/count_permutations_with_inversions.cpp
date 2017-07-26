/**
author : Shubham Sharma
Date : 26/07/2017
Ref : http://www.geeksforgeeks.org/number-of-permutation-with-k-inversions/
*/

/** ======================== Number of permutaions with k  inversions ====================================
 * ==> this is implemented using dynamic programming
 * 
 * ==> Let us suppose that you have all the permutaions of n-1 written somewhere. 
 * * so the permutaion with k inversions will put n in the last 
 * * so the permutaion with k-1 inversions will put n in 1 from last pos
 * * in same way permutaions with 0 inversions will put n just before k places from last  
*/

#include<bits/stdc++.h>
using namespace std;

int count_inversions(const int n,const int k,vector<vector<int>>& memo){
  if(n == 0) return 0;
  if(k == 0) return 1;
  
  if(memo[n][k] > 0) return memo[n][k];
  
  int sum = 0;
  for(int i = 0; i <= k ; ++i){
    
    if(i <= n-1)sum += count_inversions(n-1,k-i,memo);
    
  }
  memo[n][k] = sum;
  return sum;
  
}

int main(void){
  int n,k ; cin >> n >> k;
  vector<vector<int>> memo(n+1,vector<int>(k+1,0));
  
  cout<<count_inversions(n,k,memo)<<endl;
  
  return 0;
}
