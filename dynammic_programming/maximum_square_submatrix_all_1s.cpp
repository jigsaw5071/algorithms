/**
@Shubham Sharma
Date: 01/02/2017
*/

/*
--------------Maximum square submatrix with all 1s-----------------------------
1. The time complexity is O(m*n)
where m and n are the dimensions of the matrix
2. The space complexity is O(m*n)
*/
#include<bits/stdc++.h>
using namespace std;

/*
utility function to get the minimum
*/
int get_min(const int a,const int b,const int c){
    return (a<c)?(a<b?a:b):(c<b?c:b);
}

int get_maximum_submatrix(vector<vector<int>>& arr){
    int m=arr.size();
    int n=arr[0].size();
    
    vector<vector<int>> dp(m,vector<int>(n,0));
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(i==0 || j==0){
                dp[i][j]=arr[i][j];
                continue;
            }
            if(arr[i][j]==1){
                dp[i][j]=get_min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]) +1;
            }
            
        }
    }
    int max_row=0;
    int max_col=0;
    int max_size=0;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(dp[i][j]>max_size){
                max_size=dp[i][j];
                max_row=i;
                max_col=j;
            }
        }
    }
    cout<<"The starting coordinates of the maximum square submatrix are:";
    cout<<max_row-max_size+1<<" "<<max_col-max_size+1<<endl;
    cout<<"The size of the submatrix is :"<<max_size;
}

int main(void){
    vector<vector<int>> arr={{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
    get_maximum_submatrix(arr);               
    return 0;
}
