/*
-By Shubham Sharma
:17-09-2016
-MIT OCW
*/

/*
Dynammic Programming solution is a very impressive Algorithm design technique
for many problems to solve them in polynomial time complexity.
The time complexity for this solution is o(n*n)
The space complexity is O(n)
This algoritm is used in computational biology for several DNA analysis
*/
#include<bits/stdc++.h>
using namespace std;

/*
utility function to find the maximum of the two numbers 
*/
int _max(const int& a,const int& b){
    return a>b?a:b;
}

/*
utility stack function to print the longest increasing subsequence
*/
void _print_LIS(int *_parent,int *arr,int n){
    if(n==-1){
        return;
    }
    _print_LIS(_parent,arr,_parent[n]);
    cout<<arr[n]<<" ";
}

/*
A utility function for the longest increasing subsequence 
*/
void _LIS(int *arr,const int n){
int *_dp=(int *)malloc(n*sizeof(int));
int *_parent=(int *)malloc(n*sizeof(int));
for(int i=0;i<n;++i){
_dp[i]=1;
}
memset(_parent,-1,n*sizeof(int));

// Algorithm starts from here 
for(int i=1;i<n;++i){
    for(int j=0;j<i;++j){
        if(arr[i]>arr[j]){
            int _value=_max(_dp[i],1+_dp[j]);
            _dp[i]=_value;
            if(_value==(1+_dp[j])){
                _parent[i]=j;
            }
        }
    }
}
//Algorithm ends here

int _max_length=0;
for(int i=0;i<n;++i){
    _max_length=(_dp[i]>_max_length)?_dp[i]:_max_length;
}
cout<<"The length of the longest increasing subsequence is "<<_max_length<<endl;
_print_LIS(_parent,arr,n-1);
free(_parent);
free(_dp);    
}

int main(void){
int arr[]={ 10, 22, 9, 33, 21, 50, 41, 60 };
int n=sizeof(arr)/sizeof(arr[0]);
_LIS(arr,n);    
    
return 0;    
}
