/*
-By Shubham Sharma
-22-09-2016
*/
#include<bits/stdc++.h>
using namespace std;
/*
The time complexity of this algorithm is O(nk)
The space complexity is O(nk)
*/
/*
utilility function to evaluate the binomial coefficient in the 
number
*/
void _binomial_coefficient(const int n,const int k){
    if(n<k){
        return ;
    }
    vector<vector<int>> _dp(n+1,vector<int>(k+1));
    for(int i=1;i<=n;++i){
        for(int j=0;j<=min(i,k);++j){
         if(j==0 || i==j){
             _dp[i][j]=1;
         }
         else{
             _dp[i][j]=_dp[i-1][j-1] +_dp[i-1][j];
         }
        }
    }
    cout<<_dp[n][k]<<endl;
}
int main(void){
    int n=100;
    int k=2;
    _binomial_coefficient(n,k);
    
return 0;    
}
