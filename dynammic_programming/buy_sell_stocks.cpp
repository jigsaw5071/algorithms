/*
@Shubham Sharma
Date:07/08/2017
Ref: Tushar Roy Mission Peace
*/

/**------------------------MAXIMUM PROFIT BUY AND SELL STOCK------------------------------------------

1. Its counter questions like buying and sellin g only once oe infinitely many times can be done in a simpler way in O(N) time.
2. But in this paradigm you can buy or sell atmost K times
3. The time complexity is O(days*transactions)
4 The space complexity is O(days*transactions)
*/

#include<bits/stdc++.h>
using namespace std;

int get_max(const int a,const int b){
    return a>b?a:b;
}

int get_maximum_profit(vector<int>& arr,const int K){
    
    vector<vector<int>> dp(K+1,vector<int>(arr.size()+1,0));
    
    for(int i=1;i<=K;++i){
        int max_diff=dp[0][0]-arr[0];
        for(int j=1;j<=arr.size();++j){
            dp[i][j]=get_max(dp[i][j-1],arr[j]+max_diff);
            max_diff=get_max(max_diff,dp[i-1][j]-arr[j]);
        }
    }
    return dp[K][arr.size()];
}


int main(void){
    int K=3;
    vector<int> arr={10,22,5,75,65,80};
    cout<<get_maximum_profit(arr,K);
    return 0;
}
