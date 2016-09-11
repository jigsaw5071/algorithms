/*
-By Shubham Sharma
:11-09-2016
*/
#include<iostream>
using namespace std;

/*
Utility swap function
*/
void _swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

/*
utility function for partition of the quicksort
*/
int _partition(int *arr,const int l,const int r){
    int pivot=arr[r];
    int _pivot_index=r;
    int pIndex=l;
    int i=l;
    int _count=0;
    while(i!=_pivot_index){
        if(arr[i]==pivot){_count++;}// This is an optimiztion for duplicates
        if(arr[i]<=pivot){
            _swap(&arr[i],&arr[pIndex]);
            pIndex++;
        }
        i++;
    }
    _swap(&arr[pIndex],&arr[_pivot_index]);
    return pIndex-(_count/2);
}
/*
Utility Method to find the kth smallest element in the array
the worst case time complexity is O(n^2)
average time complexity is O(n)
*/
int _k_largest_algorithm(int *arr,const int l,const int r ,const int k){
  if(l<=r){
    int pIndex=_partition(arr,l,r);
    if(pIndex==(k-1)){return arr[pIndex];}
    else if(pIndex < (k-1)){
        return _k_largest_algorithm(arr,pIndex+1,r,k);
    }
    else{
        return _k_largest_algorithm(arr,l,pIndex-1,k);
    }
  }
  return -1;
}

int main(void){
int arr[]={12, 3, 3, 7, 4, 19, 26};
int N=sizeof(arr)/sizeof(arr[0]);
int k=3;
cout<<"The "<<k<<" smallest element is :"<<endl;
cout<<_k_largest_algorithm(arr,0,N-1,k);
return 0;    
}
