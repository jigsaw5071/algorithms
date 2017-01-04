#include<bits/stdc++.h>
using namespace std;

/*
This is one of the best method to calculate the factorial and multiply the marge numbers
It Takes O(n*3000) time to calculate the factorial
*/

/*
utility function to multiply a number with an array
*/
void multiply(const int n,vector<int>& arr){
    int sum=0;
    int carry=0;
    for(int i=0;i<arr.size();++i){
        sum=arr[i]*n+carry;
        carry=sum/10;
        sum=sum%10;
        arr[i]=sum;
    }
    while(carry>0){
        arr.push_back(carry%10);
        carry/=10;
    }
}


string get_long_factorial(const int n){
    if(n<=1){return "1";}
    if(n==2){return "2";}
    if(n==3){return "6";}
    if(n==4){return "24";}
    if(n==5){return "120";}
    if(n==6){return "720";}
    
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(2);
    arr.push_back(7);
    for(int i=7;i<=n;++i){
        multiply(i,arr);
    }
    string result="";
    for(int i=0;i<arr.size();++i){
        result=(char)(arr[i]+48)+result;
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
cout<<get_long_factorial(n)<<endl;
}
return 0;
}
