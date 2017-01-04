/*
@ Shubham Sharma
Date:04/01/2017
*/

/*
--------------------Number of digits in a number factorial------
Time complexity is o(n)
*/

#include<bits/stdc++.h>
using namespace std;

int get_factorial_digit_count(const int n){
    if(n<=3){return 1;}
    double result=0.0;
    for(int i=2;i<=n;++i){
        result+=log10(n);
    }
    return floor(result) +1;
}

int main(void){
    int n=1000;
    cout<<get_factorial_digit_count(n)<<endl;
    return 0;
}
