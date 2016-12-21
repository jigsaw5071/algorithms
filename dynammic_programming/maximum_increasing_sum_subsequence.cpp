/**
@ Shubham Sharma
Date:21/12/2016
*/

#include<bits/stdc++.h>
using namespace std;

int maximum_increasing_sum(vector<int>& arr){
    int n=arr.size();
    if(n==1){return arr[0];}
    vector<int> dp(n,0);
    for(int i=0;i<n;++i){
        dp[i]=arr[i];
    }
    for(int i=1;i<n;++i){
        int j=i-1;
        while(j>=0 && arr[j]>arr[i]){
            j--;
        }
        if(j>=0){
            dp[i]=dp[j]+arr[i];
        }
    }
    int max=dp[0];
    for(int i=1;i<n;++i){
        max=dp[i]>max?dp[i]:max;
    }
    return max;
}

int main(void){
    vector<int> arr={1, 115, 2, 3, 100, 4, 105};
    
    cout<<maximum_increasing_sum(arr);
}
