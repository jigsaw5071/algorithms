/*
@Shubham Sharma
Date:28/02/2017
ref: Tushar Roy DP
*/

/*--------------------------------WildCard Pattern Matching-------------------------------------------------------
1. This is a very important question asked in various interviews
2. The time complexity is O(row*col)
3. The space complexity is O(row*col)
**/
#include<bits/stdc++.h>
using namespace std;

bool is_wildcard_matched(string& text,string& pattern){
    
    int row=text.size();
    int col=pattern.size();
    
    vector<vector<bool>> dp(row+1,vector<bool>(col+1,false));
    
    dp[0][0]=true;
    int j=1;
    while(j<=col && pattern[j]=='*'){
        dp[0][j]=true;
        j++;
    }
    if(j<=col){
        dp[0][j]=false;
    }
    for(int i=1;i<=row;++i){
        for(int k=1;k<=col;++k){
            if(pattern[k-1]=='?' || pattern[k-1]==text[i-1]){
                dp[i][k]=dp[i-1][k-1];
            }
            else if(pattern[k-1]=='*'){
                dp[i][k]=dp[i-1][k] || dp[i][k-1];
            }
            else{
                dp[i][k]=false;
            }
        }
    }
    return dp[row][col];
}

int main(void){
    string text="abc";
    string pattern="a*b";
    if(is_wildcard_matched(text,pattern)){
        cout<<"Matching Possible"<<endl;
    }
    else{
        cout<<"Matching Not Possible"<<endl;
    }
    return 0;
}
