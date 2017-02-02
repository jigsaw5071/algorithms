
#include<bits/stdc++.h>
int get_countPS(string& str,const int i,const int j,vector<vector<int>>& dp){
    if(i>j){
        return 0;
    }
    if(i==j){
        dp[i][j]=1;
        return 1;
    }
    if((i+1)==j){
        dp[i][j]=2 + (str[i]==str[j]);
        return dp[i][j];
    }
    
    if(dp[i][j]>-1){
        return dp[i][j];
    }
    
    dp[i][j]=get_countPS(str,i,j-1,dp)+get_countPS(str,i+1,j,dp) - get_countPS(str,i+1,j-1,dp) + (str[i]==str[j])*(1 + get_countPS(str,i+1,j-1,dp));
    return dp[i][j];
}
/*You are required to complete below method */
int countPS(string str)
{
   //Your code here
   int n=str.length();
   if(n==1){return 1;}
   if(n==2){ return 2 + (str[0]==str[1]); }
   vector<vector<int>> dp(n,vector<int>(n,-1));
   get_countPS(str,0,n-1,dp);
   return dp[0][n-1];
}
 
