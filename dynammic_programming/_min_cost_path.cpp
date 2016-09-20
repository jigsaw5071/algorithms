/*
-By Shubham Sharma
:17-09-2016
*/
#include<bits/stdc++.h>
using namespace std;

/*
The time complexity of this algortihm is O(p*q)
The space complexity is O(p*q)
*/

/*
utility function to find the minimum of the three elements
*/
int _min(const int a,const int b,const int c){
    return (a<b)?(a<c?a:c):(b<c?b:c);
}

/*
utility function to find the minimum cost path
*/
int _minimum_cost_path(vector<vector<int>>& V,const int p,const int q){
    int m=V.size();
    int n=V[1].size();
    int _dp[m][n];
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(i==0 && j==0){
               _dp[i][j]=V[i][j];
            }
            else if(i==0){
            _dp[i][j]=V[i][j]+_dp[i][j-1];    
            }
            else if(j==0){
            _dp[i][j]=V[i][j]+V[i-1][j];    
            }
            else{
                _dp[i][j]=V[i][j]+_min(_dp[i-1][j-1],_dp[i-1][j],_dp[i][j-1]);
            }
        }
    }
    return _dp[p][q];
    
}

int main(void){
    vector<vector<int>> V ={ {1, 2, 3},{4, 8, 2},{1, 5, 3} };
    int p=2;
    int q=2;
    cout<<_minimum_cost_path(V,p,q)<<endl;
    
    
return 0;    
}
