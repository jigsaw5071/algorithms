/*
-By Shubham Sharma
:17-09-2016
*/

/*
It is based on the parasigm of the longest increasing subsequence
The time complexity is O(n*n)
The space complexity is O(n)
*/
#include<bits/stdc++.h>
using namespace std;

int _max(const int a,const int b){
    return a>b?a:b;
}

/*
utility function to find the longest sum usbsequence
*/
int _LSS(vector<int>& V,const int n){
    vector<int> _dp(n,1);
    for(int i=0;i<n;++i){
        _dp[i]=V[i];
    }
    for(int i=1;i<n;++i){
        for(int j=0;j<i;++j){
            if(V[i]>V[j]){
                _dp[i]=_max(_dp[i],V[i]+_dp[j]);
            }
        }
    }
    int _max_sum=_dp[0];
    for(int i=1;i<n;++i){
        _max_sum=(_dp[i]>_max_sum)?_dp[i]:_max_sum;
    }
    return _max_sum;
}

int main(void){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> V(n);
        for(int i=0;i<n;++i){
            cin>>V[i];
        }
        cout<<_LSS(V,n)<<endl;
        
    }
return 0;    
}
