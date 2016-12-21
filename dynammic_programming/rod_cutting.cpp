/**
@Shubham Sharma
:21/12/2016
*/
#include<bits/stdc++.h>
using namespace std;

int _max(const int a ,const int b){
    return a>b?a:b;
}

int maximum_price(vector<int>& arr){
    int n=arr.size();
    vector<int> dp(n+1,0);
    
    for(int i=1;i<=n;++i){
        for(int j=0;j<i;++j){
            dp[i]=_max(dp[i],dp[j]+arr[i-1-j]);
        }
    }
    return dp[n];
}

int main(void){
    vector<int> arr={1, 5, 8, 9, 10, 17, 17, 20};
    cout<<maximum_price(arr);
return 0;    
}
