/*
-By Shubham Sharma
:18-09-2016
*/

/*
The time comlexity of this algorithm is O(N*m)
The space complexity is O(N)


*/
#include<bits/stdc++.h>
using namespace std;
/*
utility function for the coin change problem
*/
int _maximum_denomination_change(vector<int>& V,const int N){
    int *_dp=(int *)malloc((N+1)*sizeof(int));
    memset(_dp,0,(N+1)*sizeof(int));
    int m=V.size();
   /*
   This was my first initial code
   for(int i=0;i<m;++i){
        for(int j=0;j<=N;++j){
            if(i==0){
                if(j%V[i] == 0){
                    _dp[j]=1;
                }
                else {
                    _dp[j]=0;
                }
            }
            else{
                if(j>=V[i]){
                        _dp[j]=_dp[j]+_dp[j-V[i]];
                }
            }
        }
    }
    cout<<endl;*/
    /*
    More beautiful code
    */
    _dp[0]=1;//because the 0 sum can be made by any denomination of 0 count
    for(int i=0;i<m;++i){
        for(int j=V[i];j<=N;++j){
            _dp[j]=_dp[j]+_dp[j-V[i]];
        }
    }
    int _result=_dp[N];
    free(_dp);
    _dp=NULL;
return _result;    
}


int main(void){
    int N=4;
    vector<int> V={1,2,3,4};
    
    cout<<_maximum_denomination_change(V,N)<<endl;
    
    
    
    
return 0;    
}
