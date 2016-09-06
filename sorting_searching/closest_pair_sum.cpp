/*
-By Shubham Sharma
:06-09-2016
*/
#include<iostream>
#include<climits>
using namespace std;

//Time complexity = O(m+n)
// If the length of the both arrays is same then it can be further optimized throw
//O(logn)

void _closest_pair(int *arr1,int *arr2,const int m,const int n,const int key){
int _minimum=INT_MAX;
int i=0;
int j=n-1;
int left_result=0;
int right_result=0;
//this is the method of the merging of the two arrays at the two points
while(i<m && j>=0){
    if(abs(arr1[i]+arr2[j]-key)< _minimum){
    left_result=arr1[i];
    right_result=arr2[j];
    _minimum=abs(arr1[i]+arr2[j]-key);
    }
    if(_minimum==0){
        break;
    }
    if(arr1[i]+arr2[j] > key){
        j--;
    }
    else{
        i++;
    }
    
}
cout<<left_result<<" "<<right_result<<endl;
    
}

int main(void){
int arr1[]={1, 4, 5, 7};
int arr2[]={10, 20, 30, 40};
int key=38;
int m=sizeof(arr1)/sizeof(arr1[0]);
int n=sizeof(arr2)/sizeof(arr2[0]);
_closest_pair(arr1,arr2,m,n,38);
    
    
return 0;    
}
