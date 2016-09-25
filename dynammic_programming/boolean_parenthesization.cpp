/*
-By Shubham Sharma
: 25-06-2016
-reference:boolean parenthsization
*/

/*
The time complexity of this algortihm is O(n*n*n)
Space complexity : o(n*n)
It uses same grounds as matrix chain multiplication
*/

#include<bits/stdc++.h>
using namespace std;

/*
utiltiy function for matrix chain multiplication 
using similar paradigm as Matrix chain multiplication
*/
int _count_boolean_Parenthesis(char *_symbol,char *_operator,const int m,const int n){
    int T[m][m];
    int F[m][m];
    for(int i=0;i<m;++i){
        for(int j=0;j<m;++j){
            T[i][j]=0;
            F[i][j]=0;
        }
    }
    for(int i=0;i<m;++i){
        T[i][i]=(_symbol[i]=='T')?1:0;
        F[i][i]=(_symbol[i]=='F')?1:0;
    }
    for(int L=2;L<=m;++L){
        for(int i=0;i<=m-L;++i){
            int j=i+L-1;
            T[i][j]=F[i][j]=0;
            for(int k=i;k<=j-1;++k){
                
                // this is for the total i and j
                int _totalL=T[i][k]+F[i][k];
                int _totalR=T[k+1][j]+F[k+1][j];
                // This logic is for maintaining the true as well as the false arra array
                if(_operator[k]=='&'){
                    // This is for the and operation
                    T[i][j]+=T[i][k]*T[k+1][j];
                    F[i][j]+=(_totalL * _totalR )-(T[i][k]*T[k+1][j]);
                }
                else if(_operator[k]=='|'){
                    // This is for the or operation
                    
                    T[i][j]+=(_totalL * _totalR) -(F[i][k]*F[k+1][j]);
                    F[i][j]+=F[i][k]*F[k+1][j];
                }
                else {
                    //this is for the xor operation
                    T[i][j]+=T[i][k]*F[k+1][j]+F[i][k]*T[k+1][j];
                    F[i][j]+=F[i][k]*F[k+1][j]+T[i][k]*T[k+1][j];
                }
            
                
            }
            
        }
    }
    
    for(int i=0;i<m;++i){
        for(int j=0;j<m;++j){
            cout<<T[i][j]<<" ";
        }
        cout<<endl;
    }
    return 20;
}




int main(void){
char _symbol[]={'T','T','F','T'};
char _operator[]={'|','&','^'};
int m=sizeof(_symbol)/sizeof(_symbol[0]);
int n=sizeof(_operator)/sizeof(_operator[0]);
cout<<_count_boolean_Parenthesis(_symbol,_operator,m,n);    
    
return 0;    
}
