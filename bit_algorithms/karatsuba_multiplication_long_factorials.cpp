

#include<bits/stdc++.h>
using namespace std;

/*
utility function to analyse the karatsuba multiplication paradigm for large
factorials
*/


/*
utility function to remove the leading zeroes
*/
string remove_leading_zeroes(string s){
    if(s.length()==0){
        return "";
    }
    int i=0;
    while(i<s.length() && s[i]=='0'){
        i++;
    }
    
    if(i==s.length()){
        return "0";
    }
    return s.substr(i);
}

/*
utiltiy function to make the lengths of the two strings same
*/
int make_equal_length(string& A,string& B){
    int a=A.length();
    int b=B.length();
    if(a==b){
        return a;
    }
    if(a>b){
        for(int i=0;i<a-b;++i){
            B='0'+B;
        }
        return a;
    }
    for(int i=0;i<b-a;++i){
        A='0'+A;
    }
    return b;
}


/*utility function to add the two strings*/
string add_two_strings(string A,string B){
    int n=make_equal_length(A,B);
    int carry=0;
    int sum=0;
    string result="";
    for(int i=n-1;i>=0;i--){
        sum=carry+(int)(A[i]-48)+(int)(B[i]-48);
        carry=sum/10;
        sum=sum%10;
        result=(char)(sum+48) + result;
    }
    if(carry>0){
        result='1'+result;
    }
    return result;
}

/*
utility function to subtract the two numbers
*/
string subtract_two_strings(string A,string B){
    int n=make_equal_length(A,B);
    string result="";
    for(int i=n-1;i>=0;i--){
        int temp=(int)(A[i]-48) -(int)(B[i]-48);
        if(temp>=0){
            result=(char)(temp+48)+result;
        }
        else{
            int j=i-1;
            while(j>0 && A[j]=='0'){
                A[j]='9';
                j--;
            }
            A[j]--;
            temp+=10;
            result=(char)(temp+48)+result;
        }
    }
    return result;
}

/*
utility function to conver num to string
*/
string num_to_string(int n){
    string result="";
    if(n==0){return "0";}
    while(n>0){
        result=(char)((n%10)+48)+result;
        n/=10;
    }
    return result;
}

/*
utility function to multiply the single digits
*/
string multiply_single_digit(string A,string B){
    if(A[0]=='0' || B[0]=='0'){return "0";}
    int result=(int)(A[0]-48)*(int)(B[0]-48);
    return num_to_string(result);
}

/*
utility function to raise a number to power 10
*/
string multiply_power_10(string s,int power){
    if(s.length()==0){
        return "";
    }
    string result=s;
    while(power--){
        result+='0';
    }
    return result;
}

/*
utility function for the karatsuba multiply
*/
string karatsuba_multiply(string X,string Y){
    X=remove_leading_zeroes(X);//removing the leading zeroes for unnecessary computations
    Y=remove_leading_zeroes(Y);
    int n=make_equal_length(X,Y);
    if(n==0){return "0";}
    if(n==1){return remove_leading_zeroes(multiply_single_digit(X,Y));}
    
    int fh=n/2;//first half
    int sh=n-fh;//second halh
    
    string X1 = X.substr(0,fh);
    string X0=X.substr(fh,sh);
    
    string Y1=Y.substr(0,fh);
    string Y0=Y.substr(fh,sh);
    
    string P1=karatsuba_multiply(X1,Y1);
    string P2=karatsuba_multiply(X0,Y0);
    
    string P3=karatsuba_multiply(add_two_strings(X1,X0),add_two_strings(Y1,Y0));
    string P4=add_two_strings(P1,P2);
    P3=subtract_two_strings(P3,P4);
    
    P1=multiply_power_10(P1,2*sh);
    P3=multiply_power_10(P3,sh);
    
    return remove_leading_zeroes(add_two_strings(P3,add_two_strings(P1,P2)));
}

/*
utility function to calculate the long factorials
*/
string long_factorial(int n){
    if(n<=0){return "1";}
    if(n==2){return "2";}
    string result="2";
    for(int i=3;i<=n;++i){
        result=karatsuba_multiply(num_to_string(i),result);
    }
    return result;
}

int main(void){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int T;
cin>>T;
while(T--){
    int n;
    cin>>n;
    cout<<long_factorial(n)<<endl;
}
return 0;
}
