/*
@Shubham Sharma
Date:24/10/2016
*/

/*
utility function to check the divisiblity by 9 .. This code is faster as it uses bitwise operations

n/9 = n/8 - n/72

n/8 = floor(n/8) + (n%8)/8;

n/9 = n/8 - (n/8)/9

n/9 = floor(n/8) + (n%8)/8 - (floor(n/8) + (n%8)/8)/9;

n/9 = floor(n/8) -(floor(n/8)-(n%8))/9
For right hand side to be an integer (floor(n/8) - (n%8) ) should be divisible by 9

*/


#include<bits/stdc++.h>
using namespace std;

bool isDivisibleBy9(int num){
	if(num==0 || num==9){ return true;}
	if(num < 9) {return false;}
	return isDivisibleBy9( (num>>3) - (num&7));
}

int main(void){
	cout<<isDivisibleBy9(243);
	return 0;
}
