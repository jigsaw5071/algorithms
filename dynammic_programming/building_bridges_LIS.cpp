/**
@Shubham Sharma
Date:01/02/2017
*/

/*
--------------------------------------------------Building Bridges Problem-------------------------------------------------------------------
1. This is a paradigm of the Longest Increasing Subsequence problem just like box stacking,longest chain pair,etc 

2. The time complexity is O(n*n) but can be reduced to O(n logn)

3. Space complexity : O(n)

4. Solution for SPOJ problem bridges:http://www.spoj.com/problems/BRIDGE/

*/

#include<bits/stdc++.h>
using namespace std;

/**
utility function to get the maximum value
*/
int get_max(const int a,const int b){
    return a>b?a:b;
}

/**
utility LIS paradigm function for building maximum bridges
*/
int get_maximum_bridges(vector<int>& arr1,vector<int>& arr2,const int n){
    if(n==1){
        return 1;
    }
    vector<pair<int,int> > arr(n);
    for(int i=0;i<n;++i){
        arr[i]=make_pair(arr1[i],arr2[i]);
    }
    sort(arr.begin(),arr.end(),[](pair<int,int> x,pair<int,int> y){ return x.second<y.second;});
    vector<int> dp(n,1);
    for(int i=1;i<n;++i){
        for(int j=0;j<i;++j){
            if(arr[i].first > arr[j].first){
                dp[i]=get_max(dp[i],1+dp[j]);
            }
        }
    }
    int result=dp[0];
    for(int i=1;i<n;++i){
        result=get_max(result,dp[i]);
    }
    return result;
}

int main(void){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> arr1(n),arr2(n);
        for(int i=0;i<n;++i){
            cin>>arr1[i];
        }
        for(int i=0;i<n;++i){
            cin>>arr2[i];
        }
        cout<<get_maximum_bridges(arr1,arr2,n)<<endl;
    }
    return 0;
}
