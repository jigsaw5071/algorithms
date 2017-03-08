/**
@Shub/am Sharma
Date:08/03/2017
Ref: geeksforgeeks
*/

/*-------------------------Efficient Binomial Coefficent-------------------

1. The time complexity is O(k)
2. the space complexity is O(1)

*/

#include<bits/stdc++.h>
using namespace std;

int get_coefficient(const int n,int k){
    if(k==0){return 1;}
    if(k==1){return n;}
    if(k>n-k){
        k=n-k;
    }
    int res=1;
    for(int i=0;i<k;++i){
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}

int main(void){
    int n=7;
    int k=6;
    cout<<get_coefficient(n,k)<<endl;
    return 0;
}
