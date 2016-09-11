/*
-By Shubham Sharma 
:11-09-2016
*/
#include<iostream>
using namespace std;
// This program showcases the inefficiency of ternary search over binary search


/*
Utility function to find the ternary search elements
T(n)= T(n/3) +4 {4 comparisons}
Total comperisons in worst case : 4 (log n / log 3) +1
*/
int _ternary_search(int *arr,int l,int r,const int _key){
if(l<=r){
int mid1=l+(r-l)/3;
int mid2=mid1+(r-l)/3;
if(arr[mid1]==_key){return mid1;}
if(arr[mid2]==_key){return mid2;}
if(_key<arr[mid1]){
    return _ternary_search(arr,l,mid1-1,_key);
}
else if(_key>arr[mid2]){
    return _ternary_search(arr,mid2+1,r,_key);
}
else{
    return _ternary_search(arr,mid1+1,mid2-1,_key);
}
}
return -1;
} 

int main(void){
int arr[]={1,2,3,4,5,6};
int N=sizeof(arr)/sizeof(arr[0]);
cout<<_ternary_search(arr,0,N-1,5);
return 0;    
}
