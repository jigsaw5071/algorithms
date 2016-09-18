/*
-By Shubham Sharma
:17-09-2016

*/

/*
This is a very classical problem in dynammic programming.
2. It is used to find the difference between the two files in the system
3.It is used in the bioinformatics
4. The time complexity is O(m*n)
where m = length of string 1 and n=length of the string 2 
5. The space  complexity of this algorithm is O(mn)
*/

#include<bits/stdc++.h>
using namespace std;

/*
util function to find the maximum of any value
*/
int _max(const int& a ,const int& b){
    return (a>b)?a:b;
}

/*
utility function to print the LCS
*/

void _print_LCS(vector<vector<int>>& _dp,string& x,int n,int m ){
   
   if(n==0 || m==0){
       return ;
   }
   if(_dp[n][m]>_dp[n-1][m] && _dp[n][m]>_dp[n][m-1]){
       _print_LCS(_dp,x,n-1,m-1);
       cout<<x[n-1]<<" ";
   }
   else{
       if(_dp[n][m]==_dp[n-1][m]){
           _print_LCS(_dp,x,n-1,m);
       }
       else{
           _print_LCS(_dp,x,n,m-1);
       }
   }
    
}

/*
utility function for the longest common subsequence
*/
void _LCS(string& x,string& y){
    int n=x.length();
    int m=y.length();
    vector<vector<int>> _dp(n+1,vector<int>(m+1));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(x[i-1]==y[j-1]){
                _dp[i][j]=1+_dp[i-1][j-1];
            }
            else{
                _dp[i][j]=_max(_dp[i][j-1],_dp[i-1][j]);
            }
        }
    }
    cout<< "The length of the longest common subsequece is : "<<_dp[n][m]<<endl;
    cout<<"The longest common subsequence is: "<<endl;
    
    _print_LCS(_dp,x,n,m);
}

int main(void){
 string x= "AGGTAB";
 string y = "GXTXAYB";
 
 _LCS(x,y);
    
return 0;    
}
