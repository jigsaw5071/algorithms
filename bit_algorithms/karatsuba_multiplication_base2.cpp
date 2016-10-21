/*
@Shubham Sharma
21/10/2016
*/

/*
 Code for the karatsuba multiplication used in high precison computation
 Time Complexity : 0 ( log n ^ 1.58)
 Space Complexity:o(1)
 
 Can be extended for any bases r 
 
 Let X = X1 * r^(n/2) + X0 * r^(n/2)
 Let Y= Y1 * r(n/2)   + Y0 * r^(n/2)
 
 Z=X*Y
  = (X1 * r^(n/2) + X0 * r^(n/2)) * (Y1 * r(n/2)   + Y0 * r^(n/2))
  = X1*Y1*r^n + ((X1+X0)(Y1+Y0) - X0Y0- X1Y1)*r^n/2+ X0Y0
 
 Recurrence Relation:
 T(n) = 3 T(n/2) + O(n)
 
*/
#include<bits/stdc++.h>
using namespace std;

/*
utility function to make the string length equal for multiplication or addition
*/
int _make_equal_length(string& a,string& b){
    int len_a=a.length();
    int len_b=b.length();
    if(len_a > len_b){
        for(int i=0;i<len_a - len_b;++i){
            b='0'+b;
        }
        return len_a;
    }
    if(len_b >len_a){
        for(int i=0;i<len_b - len_a;++i){
            a='0'+a;
        }
    }
    return len_b;
}

/*
utility function to add the two strings
*/
string _add_two_strings(string a,string b){
    string result="";
    int n=_make_equal_length(a,b);
    char carry='0';
    
    for(int i=n-1;i>=0;i--){
        char sum =(a[i]==b[i])?'0':'1';
             sum = (sum==carry)?'0':'1';
             result=sum+result;
             carry=((a[i]=='1' && b[i]=='1')||(a[i]=='1' && carry=='1')||(b[i]=='1' && carry=='1'))?'1':'0';
    }
    if(carry=='1'){
        result=carry+result;
    }
    return result;
}

/*
utility function to multiply single bits
*/
uint64_t _single_bit_multiply(string a,string b){
    return (a[0]=='1' && b[0]=='1')?1:0;
}

/*
recursive wrapper function for karatsuba multiplication
*/
uint64_t _karatsuba_multiply(string X,string Y){
int n=_make_equal_length(X,Y);
if(n==0){return 0;}
if(n==1){return _single_bit_multiply(X,Y);}

int fh=n/2; // fh stands for first half
int sh=n-fh;//sh stands for second half

string X1 = X.substr(0,fh);
string X0 = X.substr(fh,sh);

string Y1 = Y.substr(0,fh);
string Y0 = Y.substr(fh,sh);

uint64_t P1 = _karatsuba_multiply(X1,Y1);

uint64_t P2 = _karatsuba_multiply(X0,Y0);

uint64_t P3 = _karatsuba_multiply(_add_two_strings(X1,X0),_add_two_strings(Y1,Y0));
P3=P3-P1-P2;
return P1*(1<<(2*sh)) + P3*(1<<sh) + P2;
}


int main(void){
    string a="1111";
    string b="111";
    cout<<_karatsuba_multiply(a,b);
    
return 0;    
}
