/*
@Shubham Sharma
21/10/2016
*/

/*
 Code to find the binary representation of a number
 
 Time Complexity :O(logn)
 space complexity : O(1)
*/
#include<bits/stdc++.h>
using namespace std;

string _get_binary_rep(int num){
    string result;
    while(num>0){
        if(num & 1){ 
            result=(char)49 + result;
        }
        else{
            result=(char)48 + result;
        }
        num=num>>1;
    }
    return result;
}

int main(void){
    int num=15;
    cout<<_get_binary_rep(num);
return 0;    
}
