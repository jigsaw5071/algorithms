/*
@Shubham Sharma
21/10/2016
http://code.geeksforgeeks.org/0j2X8u
*/

/*
 Code for the karatsuba multiplication used in high precison computation for base 10
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
    char carry=0;
    
    for(int i=n-1;i>=0;i--){
        int sum = carry + (a[i]-'0') + (b[i]-'0');
        carry=sum/10;
        sum=sum%10;
        result=(char)(sum+48) + result;
        }
    if(carry>0){
        result=(char)(carry+48)+result;
    }
    return result;
}

/*
utility function for the subtraction of two strings
*/
string _subtract_two_strings(string a,string b){
    string result="";
    int n=_make_equal_length(a,b);
    for(int i=n-1;i>=0;i--){
        int temp = (a[i]-'0')-(b[i]-'0');
        if(temp>=0){
            result=(char)(temp+48) + result;
        }
        else{
            int j=i-1;
            while(a[j]=='0'){
                a[j]='9';
                j--;
            }
            a[j]=(char)(((int)(a[j]-48) -1 )+48);
            temp=temp+10;
            result=(char)(temp+48) + result;
        }
        
    }
    return result;
}


/*
utility function to convert num to string
*/
string _num_to_string(int num){
    string result="";
    while(num>0){
        result= (char)((num%10)+48)  + result;
        num=num/10;
    }
    return result;
}

/*
utility function to multiply single bits
*/
string _single_digit_multiply(string a,string b){
    int v1=a[0]-'0';
    int v2=b[0]-'0';
    return _num_to_string(v1*v2);
}

/*
utility function to multiply by power of 10
*/
string _multiply_power_10(string a,int power){
    for(int i=0;i<power;++i){
        a+='0';
    }
    return a;
}

/*
recursive wrapper function for karatsuba multiplication
*/
string _karatsuba_multiply(string X,string Y){
int n=_make_equal_length(X,Y);
if(n==0){return "0";}
if(n==1){return _single_digit_multiply(X,Y);}

int fh=n/2; // fh stands for first half
int sh=n-fh;//sh stands for second half

string X1 = X.substr(0,fh);
string X0 = X.substr(fh,sh);

string Y1 = Y.substr(0,fh);
string Y0 = Y.substr(fh,sh);

string P1 = _karatsuba_multiply(X1,Y1);

string P2 = _karatsuba_multiply(X0,Y0);

string P3 = _karatsuba_multiply(_add_two_strings(X1,X0),_add_two_strings(Y1,Y0));
P3=_subtract_two_strings(P3,_add_two_strings(P1,P2)); //P3=P3-P1-P2;
P1=_multiply_power_10(P1,2*sh); //P1*(pow(10,2*sh))
P3=_multiply_power_10(P3,sh);//P3*(pow(10,sh))
return _add_two_strings(P1,_add_two_strings(P3,P2));
}

/*
utility function to remove the leading zeroes from the strings
*/
string _remove_leading_zeroes(string a){
    if(a.length()<=1){return a;}
    if(a[0]!='0'){return a;}
    string result="";
    int i=0;
    while(a[i]=='0' && a[i+1]=='0'){
        i++;
        if(i==(a.length()-1)){
            result+='0';
            return result;
        }
    }

    for(int j=i+1;j<a.length();++j){
        result+=a[j];
    }
    return result;
}

int main(void){
    string a="0485004545";
    string b="0092436556";
    cout<<_remove_leading_zeroes(_karatsuba_multiply(a,b));
    
return 0;    
}
