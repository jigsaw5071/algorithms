/*
-By Shubham Sharma
:11-09-2016
*/

#include<iostream>
using namespace std;
//In this algorithm,we are taking last element as the pivot
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int __partition(int *arr,const int l,const int r){
    int pivot_index=r;
    int pivot=arr[r];
    int pIndex=l;
    int i=l;
    int _count_same_elements=0;
    while(i!=pivot_index){
        //This is the further optimization on the quick sort if more than one elements 
        // are same and one among them is the pivot
        if(arr[i]==pivot){_count_same_elements++;}
        
        if(arr[i]<=pivot){
            swap(arr[i],arr[pIndex]);
            pIndex++;
        }
        i++;
    }
    swap(arr[pIndex],arr[pivot_index]);
    return pIndex-(_count_same_elements/2);
}
void _quickSort(int *arr,const int l,const int r){
if(l<r){
int pIndex=__partition(arr,l,r);
_quickSort(arr,l,pIndex-1);
_quickSort(arr,pIndex+1,r);
}    
}
int main(void){
int arr[]={7,7,7,7,7};
int N=sizeof(arr)/sizeof(arr[0]);
_quickSort(arr,0,N-1);
for(int i=0;i<N;++i){
    cout<<arr[i]<<" ";
}
return 0;    
}
