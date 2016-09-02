#include<iostream>
using namespace std;

void _swap(int *a,int *b){
int temp=*a;
*a=*b;
*b=temp;
}

int _partition(int *arr,const int l,const int r){
int pivot=arr[r];
int pivot_index=r;
int pIndex=l;
int i=l;
while(i!=r){
if(arr[i]<=pivot){
_swap(&arr[i],&arr[pIndex]);
pIndex++;
}
i++;
}
_swap(&arr[pIndex],&arr[pivot_index]);
return pIndex;
}

void _quickSort(int *arr,int l,int r){
while(l<r){

int pIndex=_partition(arr,l,r);
if(pIndex-l > r-pIndex){
_quickSort(arr,pIndex+1,r);
r=pIndex-1;
}
else{
_quickSort(arr,l,pIndex-1);
l=pIndex+1;
}


}
}

int main(void){
int arr[]={10, 7, 8, 9, 1, 5};
int N=sizeof(arr)/sizeof(arr[0]);
_quickSort(arr,0,N-1);
for(int i=0;i<N;++i){
cout<<arr[i]<<" ";
}
}
