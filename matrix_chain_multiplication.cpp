/*
-By Shubham Sharma
:22-09-2016
*/
/*
The time complexity of this algorithm is O(n*n*n)
The space complexity is O(n*n)
It is a classical algorithm that is used in computational 
mathematics


*/
#include<bits/stdc++.h>
using namespace std;

/*
utility function for the matrix chain multiplication
*/
void _matrix_chain_multiplication(int *p,const int n){
    vector<vector<int>> _dp(n,vector<int>(n));
    vector<vector<pair<int,int>>> _parent(n,vector<pair<int,int>>(n));
    for(int i=0;i<n;++i){
        _dp[i][i]=0; // The cost of multiplying single matrix is 0
        _parent[i][i]=make_pair(-1,-1);
    }
    
    for(int L=2;L<n;++L){
        
        for(int i=1;i<=n-L;++i){
            int j=i+L-1;
            _dp[i][j]=INT_MAX;
            
            for(int k=i;k<=j-1;++k){
            
            int _cost=_dp[i][k]+_dp[k+1][j]+p[i-1]*p[k]*p[j];
            if(_cost<_dp[i][j]){
                _dp[i][j]=_cost;
                _parent[i][j]=make_pair(i,k);
            }
            
            }
        }
    }
   cout<<"The relative printing of the matrixes is :"<<endl;
   
   char result[2*(n-1)];
   for(int i=0;i<(2*(n-1))-1;++i){
       if(i & 1){
           result[i]='*';
       }
       else {
           result[i]=(i/2)+49;
       }
   }
   
int i=1;
int j=n-1;
while(_parent[i][j].first!=_parent[i][j].second){
    int k=_parent[i][j].second;
    result[(k-1)*2+1]=')';
    i=_parent[i][j].first;
    j=_parent[i][j].second;
}
for(int i=0;i<(2*(n-1))-1;++i){
       cout<<result[i]<<" ";
   }
    
}

int main(void){
    int p[]={1,2,3,4};
    int n=sizeof(p)/sizeof(p[0]);
    _matrix_chain_multiplication(p,n);
    
return 0;    
}
