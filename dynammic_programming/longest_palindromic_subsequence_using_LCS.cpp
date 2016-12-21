/**
@ Shubham Sharma
Date-21/12/2016
*/

/*
Longest Palindromic Subsequence

Time Complexity : O(n^2)
Space Complexity: O(n^2)

It uses the longest common Subsequence routine on the string and its reverse
*/

#include<bits/stdc++.h>
using namespace std;

int _max(const int a,const int b){
    return a>b?a:b;
}

void find_LCS(vector<vector<int>>& dp,const int i,const int j,string& result,string& R,string& S){
    if(i==0 || j==0){
        return;
    }
    if(R[i-1]==S[j-1]){
        find_LCS(dp,i-1,j-1,result,R,S);
        result+=R[i-1];
        return;
    }
    if(dp[i][j-1]>dp[i-1][j]){
        find_LCS(dp,i,j-1,result,R,S);
        return;
    }
    find_LCS(dp,i-1,j,result,R,S);
}

void get_longest_length(string& S){
    int n=S.length();
    string R(S.rbegin(),S.rend());
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(R[i-1]==S[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=_max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    cout<<"The length of the longest palindromic subsequence is: "<<dp[n][n]<<endl;
    
    string result="";
    find_LCS(dp,n,n,result,R,S);
    
    cout<<"The longest Palindromic Subsequence is : "<<result<<endl;
    
}

int main(void){
    string S="GEEKS FOR GEEKS";
    get_longest_length(S);
    
return 0;    
}
