/*
@Shubham Sharma
21/10/2016
*/

/*
Swap two variables without using temp variables
Time Complexity :O(1)
Space Complexity:no space
*/
#include<bits/stdc++.h>
using namespace std;

/*
swap using xor operator
*/
void _swap_xor(int& a,int& b){
    if(a==b){return ;}
    a=a^b;
    b=a^b;
    a=a^b;
}

/*
swap using arithmetic
*/
void _swap_add(int& a,int& b){
    if(a==b){return;}
    a=a+b;
    b=a-b;
    a=a-b;
    // this function can generally lead to overflow
}

int main(void){
    int a=25;
    int b=40;
    _swap_xor(a,b);
    cout<<a<<" "<<b<<endl;
    
return 0;    
}
