/*
@Shubham Sharma
Date:24/10/2016
*/

/*
swap two nibbles in a byte

*/


#include<bits/stdc++.h>
using namespace std;

unsigned char swapNibbles(unsigned char num) 
{
	return ((num & 0XF0) >> 4) | ((num & 0X0F)<<4);
}

int main(void){
	unsigned char num=100;
	unsigned int x=swapNibbles(num);
	cout<<x;

	return 0;
}
