/*
@Shubham Sharma
Date:19/01/2017
*/

/*
----------------------------------Chain Pair Algorithm------------------------------------------------------------------

1. This problem is a variation of longest increasing subsequence and also activity selection probelm
2. Time complexity : O(n*n)
3. Space Complexity: O(n*n)
*/

#include<bits/stdc++.h>
using namespace std;

/*
utility function to get the maximum value
*/
int get_max(const int a,const int b){
    return a>b?a:b;
}

/**
utility function to print the maximum chain
*/
void print_chain(vector<pair<int,int>>& arr,vector<int>& parent,const int n){
    if(n==-1){
        return;
    }
    print_chain(arr,parent,parent[n]);
    cout<<arr[n].first<<" "<<arr[n].second<<"   ";
}

/*
utility function for the maximum chain length
*/
void maximum_chain_length(vector<pair<int,int>>& arr){
    int n=arr.size();
    vector<int> dp(n,1);
    vector<int> parent(n,-1);
    for(int i=1;i<n;++i){
        for(int j=0;j<i;++j){
            if(arr[i].first > arr[j].second){
                int value=get_max(dp[i],1+dp[j]);
                dp[i]=value;
                if(value==1+dp[j]){
                    parent[i]=j;
                }
            }
        }
    }
    
    int max_index=0;
    for(int i=1;i<n;++i){
        max_index=(dp[i]>dp[max_index])?i:max_index;
    }
    print_chain(arr,parent,max_index);
    
    
}

int main(void){
    vector<pair<int,int>> arr={{5, 24}, {15, 25},
                          {27, 40}, {50, 60}};
                          
    maximum_chain_length(arr);                      
    return 0;
}
