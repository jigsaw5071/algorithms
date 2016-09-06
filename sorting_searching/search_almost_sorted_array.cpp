/*
-By Shubham Sharma
-06-09-2016
*/
#include<iostream>
using namespace std;

//this algorithm works in O(logn) time
//binary search is used as the application
//maximum displacement from the original position is 1

/*
Binary Search
*/
int _binary_search(int *arr,int l,int r,int key){

if(r>=l){
 int mid=l+(r-l)/2;
 if(arr[mid]==key){return mid;}
 if(mid>l && arr[mid-1]==key){return mid-1;}
 if(mid<r && arr[mid+1]==key ){return mid+1;}
 
 if(arr[mid]>key){
     return _binary_search(arr,mid+2,r,key);
 }
 else{
     return _binary_search(arr,l,mid-2,key);
 }
    
}
 return -1;   
}
int main(void){
int arr[]={10, 3, 40, 20, 50, 80, 70};
int key=40;
int N=sizeof(arr)/sizeof(arr[0]);
int result_index=_binary_search(arr,0,N-1,key);
if(result_index==-1){
    cout<<"Not Present"<<endl;
}
else{
    cout<<result_index;
}
return 0;    
}
