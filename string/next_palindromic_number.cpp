#include<bits/stdc++.h>
using namespace std;

/*
utility function to check whether a number is prime or not
*/
bool is_prime(const int N){
    if(N<2){return false;}
    if(N==2 || N==3 || N==5 || N==7){return true;}
    for(int p=2;p*p<=N;++p){
        if(N%p==0){return false;}
    }
    return true;
}

/*
utility function to reverse a number
*/
int get_reverse(int n){
    if(n>=0 && n<=9){return n;}
    int result=0;
    while(n>0){
        result=10*result+(n%10);
        n/=10;
    }
    return result;
}

/*
utiltiy function to check whether a number is palindrome or not
*/
bool is_palindrome(const int n){
    return n==get_reverse(n);
}

/*
utility function to count the digits in a number 
*/
int get_digit_count(int n){
    if(n<10){return 1;}
    int result=0;
    while(n>0){
        result++;
        n/=10;
    }
    return result;
}

/*
utility function to get the next palindrome
*/
int get_next_palindrome(int n){
    int count=get_digit_count(n);
    if(count & 1){
        // number of digits is odd
        int rem=pow(10,(int)(count/2));
        int second_half=n%(rem);
        n=n/pow(10,count/2);
        int center_half=n%10;
        n=n/10;
        int first_half=n;
        
        if(first_half==(pow(10,(int)(count/2))-1) && center_half==9 && second_half==(pow(10,(int)(count/2))-1)){
            return pow(10,count) +1;
        }
        
        if(get_reverse(first_half)<=second_half){
            if(center_half<9){
                center_half+=1;
                return (first_half*10+center_half)*pow(10,(int)(count/2)) + get_reverse(first_half);
            }
            else{
                center_half=0;
                first_half+=1;
                return (first_half*10+center_half)*pow(10,(int)(count/2)) + get_reverse(first_half);
                
            }
        }
        else{
            return (first_half*10+center_half)*pow(10,(int)(count/2)) + get_reverse(first_half);
        }
    }
    else{
        //number of digits is even
        int first_half=n/pow(10,count/2);
        int second_half=n-first_half*pow(10,count/2);
        
        if(first_half==(pow(10,count/2)-1) && second_half==(pow(10,count/2)-1)){
            return pow(10,count) + 1;
        }
        
        while(get_reverse(first_half) <= second_half){
            first_half++;
        }
        return first_half*(pow(10,count/2)) +get_reverse(first_half);
    }
}

/*
utility function to find the next prime palindrome
*/
int next_prime_palindrome(int n){
    // optimizing the single digit input cases --no need for calculation
    if(n<=2){return 2;}
    if(n<=3){return 3;}
    if(n<=5){return 5;}
    if(n<=7){return 7;}
    if(n<=11){return 11;}
    
    if(!is_palindrome(n)){
        n=get_next_palindrome(n);
    }
    while(!is_prime(n)){
        n=get_next_palindrome(n);
    }
    return n;
}

int main(void){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int T;
cin>>T;
while(T--){
int n;
cin>>n;
cout<<next_prime_palindrome(n)<<endl;
}
return 0;
}
