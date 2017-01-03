#include<bits/stdc++.h>
using namespace std;

/**
This is a dp based algorithm based on min edit distance paradigm of dynamic 
programming

1. Not even inserts , it can even work for deletion and even for minimum replaces
*/

bool is_palindrome(string& s){
    if(s.length()<=1){return true;}
    int i=0;
    int j=s.length()-1;
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

/*
utiltiy function to find the minimum fo two elements
*/
int _min(const int a,const int b){
    return a<b?a:b;
}

/*
utility function for memoize routine
*/
int minimum_insert_util(const int i,const int j,string& s,vector<vector<int>>& dp){
    if(i>j){
        return 0;
    }
    if(i==j){
        dp[i][j]=0;
        return dp[i][j];
    }
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    if(s[i]==s[j]){
        dp[i][j]=minimum_insert_util(i+1,j-1,s,dp);
    }
    else{
        dp[i][j]=_min(1+minimum_insert_util(i,j-1,s,dp),1+minimum_insert_util(i+1,j,s,dp));
    }
    return dp[i][j];
}


int minimum_insert(string& s){
    if(s.length()<=1){return 0;}
    if(is_palindrome(s)){return 0;}
    
    int n=s.length();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    
    return minimum_insert_util(0,n-1,s,dp);
}


int main(void){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int T;
cin>>T;
while(T--){
string s;
cin>>s;
cout<<minimum_insert(s)<<endl;
}
return 0;
}
