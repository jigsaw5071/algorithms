/*
-By Shubham Sharma
:09-09-2016
*/
#include<iostream>
using namespace std;

// This functions shows the basic implementation of function algorithms in 
// implementing the generic functions

int _compare(const int a,const int b){
    return (a>b)?1:-1;
}

void _bubble_sort(int *arr,const int N,int (*p)(int,int)){
    for(int i=0;i<N-1;++i){
        for(int j=0;j<N-i-1;++j){
            if(p(arr[j],arr[j+1])<0){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    
}

int main(void){
int arr[]={2, 1,4 ,3 ,7 ,5 ,6};
int N=sizeof(arr)/sizeof(arr[0]);
_bubble_sort(arr,N,_compare);
for(int i=0;i<N;++i){
  cout<<arr[i]<<" ";
}
return 0;    
}
