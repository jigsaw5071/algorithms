/*
@Shubham Sharma
date:21/12/2016
*/

/*
Partition Problem


*/


#include<bits/stdc++.h>
using namespace std;

bool is_partionable(vector<int>& arr){
    int sum=0;
    int n=arr.size();
    for(int i=0;i<n;++i){
        sum+=arr[i];
    }
    if(sum & 1){
        return false;
    }
    sum=sum/2;
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
    for(int i=0;i<=n;++i){
        for(int j=0;j<=sum;++j){
            if(j==0){
                dp[i][j]=true;
                continue;
            }
            if(i==0){
                dp[i][j]=false;
                continue;
            }
            dp[i][j]=dp[i-1][j];
            if(j>=arr[i-1]){
                dp[i][j]=dp[i][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }
  
    
    return dp[n][sum];
}

int main(void){
    vector<int> arr={3, 1, 1, 2, 2, 1};
    if(is_partionable(arr)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}
