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
    while(i!=pivot_index){
        if(arr[i]<=pivot){
            swap(arr[i],arr[pIndex]);
            pIndex++;
        }
        i++;
    }
    swap(arr[pIndex],arr[pivot_index]);
    return pIndex;
}
void _quickSort(int *arr,const int l,const int r){
if(l<r){
int pIndex=__partition(arr,l,r);
_quickSort(arr,l,pIndex-1);
_quickSort(arr,pIndex+1,r);
}    
}
int main(void){
int arr[]={1,2,3,4,5,6,7};
int N=sizeof(arr)/sizeof(arr[0]);
_quickSort(arr,0,N-1);
for(int i=0;i<N;++i){
    cout<<arr[i]<<" ";
}
return 0;    
}
