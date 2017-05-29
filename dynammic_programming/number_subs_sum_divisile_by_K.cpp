/**
author : Shubham Sharma
Ref : http://www.geeksforgeeks.org/number-subsequences-string-divisible-n/
" It's after we have lost everything then we are free to do anything - Tyler Durden(Fight Club) "

*/

/**

Problem Statement: count the number of subsequences whose sum is divisible by K

*/

#include<bits/stdc++.h>
using namespace std;
#define fastin cin.tie(NULL);ios_base::sync_with_stdio(false)

int main(void){
  int arr[] = {1,2,4,1};
  int K = 5;
  int n = sizeof(arr)/sizeof(arr[0]);
  
  int dp[n][K];
  memset(dp,0,sizeof(dp));
  dp[0][arr[0]%K]++;
  
  for(int i=1;i<n;++i){
    dp[i][arr[i]%K]++;
    for(int j=0;j<K;++j){
    //first excluding the current index i from all the subsequences from 0:i-1
    dp[i][j]+=dp[i-1][j];
    
    //including the current index in all the subsequences from 0:i-1
    dp[i][(j+arr[i])%K]+=dp[i-1][j];
  }
  }
   cout<<dp[n-1][0]<<endl;
  
  return 0;
}
