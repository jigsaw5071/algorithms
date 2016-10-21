/*
@Shubham Sharma
21/10/2016
*/

/*
 Code to swap all the odd and the even bits
 Time Complaexity: o(1);
 Space Complexity:o(1)
*/
#include<bits/stdc++.h>
using namespace std;

int _swap_odd_even(uint32_t num){
    uint32_t even=num & 0xAAAAAAAA;
    uint32_t odd=num & 0x55555555;
    even=(even>>1);
    odd=(odd<<1);
    return even|odd;
}

int main(void){
    int num=23;
    cout<<_swap_odd_even(num);
return 0;    
}
