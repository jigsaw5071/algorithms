/**
@ Shubham Sharma
Date-21/12/2016
*/

/*
Longest Palindromic Subsequence

Time Complexity : O(n^2)
Space Complexity: O(n^2)

using the algorithm
if(str[i]==str[j]){
    L[i][j]=2+L[i+1][j-1]
}
else{
    L[i][j]=_max(L[i][j-1],L[i+1][j]);
}
*/

#include<bits/stdc++.h>
using namespace std;

int _max(const int a,const int b){
    return a>b?a:b;
}

int get_longest_length(const int l,const int r,string& S,vector<vector<int>>& dp){
    if(l>r){
        return 0;
    }
    if(l==r){
        dp[l][r]=1;
        return 1;
    }
    if(S[l]==S[r]){
        dp[l][r]=2+get_longest_length(l+1,r-1,S,dp);
        
    }
    else{
        dp[l][r]=_max(get_longest_length(l,r-1,S,dp),get_longest_length(l+1,r,S,dp));
    }
    return dp[l][r];
}

int main(void){
    string S="GEEFG";
    int n=S.length();
    vector<vector<int>> dp(n,vector<int>(n,0));
    cout<<get_longest_length(0,n-1,S,dp);
    
return 0;    
}
