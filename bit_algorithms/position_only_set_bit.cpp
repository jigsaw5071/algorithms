/*
@Shubham Sharma
21/10/2016
*/

/*
 Code to find the position of the only set bit
 Time Complaexity: o(logn);
 Space Complexity:o(1)
*/
#include<bits/stdc++.h>
using namespace std;

int _find_position_set_bit(int num){
    if((num & (num-1))!=0 ){return -1;}
    int position=0;
    while(num>0){
        num=num>>1;
        position++;
    }
    return position;
}

int main(void){
    int num=128;
    cout<<_find_position_set_bit(num);
return 0;    
}
