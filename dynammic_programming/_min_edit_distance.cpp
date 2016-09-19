/*
-By Shubham Sharma 
:17-09-2016
*/

/*
The time complexity of this algorithm is O(m*n)
where m=length of string A 
and n=length of string B 

The space complexity is O(m*n)

This algortihm is used in various places and is a classical optimisation 
problem in case of the strings

One good paradigm of this routine is to find all the closest words in dictionary 
to a particular words

It defines the degree of the distance between the two strings

Logic:
Let the length of string1 be m
Let the length of the string2 be n 

if(A[m]== B[n]) recur for Edit_Distance(m-1,n-1)
else
_min(Edit_Distance(m,n-1)/// insert in the first string1
 Edit_Distance(m-1,n) //remove from the first string
 Edit_Distance(m-1,n-1) // replace in the first string
 
 The cost of these three operations is considerd constant

)
*/

#include<bits/stdc++.h>
using namespace std;

/*
utiltiy function to find the minimum of the two elements
*/
int _min(const int a,const int b,const int c){
    
    return (a<b)?((a<c)?a:c):((b<c)?b:c);
}

/*
Utility function for the minimum edit distance
*/
int _minimum_edit_distance(string& A,string& B,const int m,const int n){
    vector<vector<int>> _dp(m+1,vector<int>(n+1));
    _dp[0][0]=0;
    for(int j=1;j<=n;++j){
        _dp[0][j]=j;
    }
    for(int i=1;i<=m;++i){
        _dp[i][0]=i;
        for(int j=1;j<=n;++j){
            if(A[i-1]==B[j-1]){
                // This is the case when the ith charcter of A matches to jth character of bits
                _dp[i][j]=_dp[i-1][j-1];
            }
            else{
                
                _dp[i][j]= 1+ _min(_dp[i][j-1],  //This is for the insert in string 1
                    _dp[i-1][j],//This is for the remove from the first string                    
                     _dp[i-1][j-1]); // This is for the replace in the string 1
            }
        }
    }
    return _dp[m][n];
    
}

int main(void){
    string A="sunday";
    string B="saturday";
    cout<<"The minimum edit distance is :"<<endl;
    cout<<_minimum_edit_distance(A,B,A.length(),B.length());
    
return 0;    
}
