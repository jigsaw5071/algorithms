/*
@Shubham Sharma
Date:24/10/2016
*/

/*
function to check if the binary representaion fo the number is a palindrome or not

*/


#include<bits/stdc++.h>
using namespace std;

int countOnes(int num){
	int count=0;
	while(num>0){
        num = num & (num-1);
		count++;
	}
	return count;
}

int getLeftMostSetBit(int num){
	int count=0;
	while(num > 1){
		num=num>>1;
		count++;
	}
	return count;
}

bool isBinaryRepresentationPalindrome(int num){
	if(num==0){return true;}

    if(((num) & (num-1))==0 ) { return false;} // power of 2 cannot be a palindrome

    if((num & (num+1))==0 ){return true;} // 2^n -1  are always palindromes

    if(countOnes(num) & 1 ) {return false; }  // representations containing odd numbers of 1s are also not palindromes
    int leftSetBit=getLeftMostSetBit(num); //  time complexity is logg n
    bool result=true;
    int i=0;
    int j=leftSetBit;
    while(j>i){
      if(((num & (1<<j)) >0 && ((num & (1<<i)) >0 )) || ((num & (1<<j)) ==0 && ((num & (1<<i)) ==0 ))  ){
      	i++;
      	j--;
      }
      else{
      	result=false;
      	break;
      }
    }
    return result;
}

int main(void){
	cout<<isBinaryRepresentationPalindrome(1<<15 + 1<<16)<<endl;

	return 0;
}
