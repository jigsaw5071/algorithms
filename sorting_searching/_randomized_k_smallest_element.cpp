/*
-By Shubham Sharma
:11-09-2016
*/
#include<iostream>
#include<time.h>
#include<climits>
using namespace std;

// The expected time complexity of this algorithm is O(n) but still in the 
// worst case it is O(n*n)

/*
Utility function for swap
*/
void _swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

/*
utility function for the randomized partition with the uniform random distribution in the input range
*/
int _random_partition(int *arr,const int l,const int r){
 srand(time(NULL));  //Initialize random seed 
    int N=r-l+1;
    int _random_index=l + rand()%N; // generating the random index
    int _pivot_index=r;
    _swap(&arr[_pivot_index],&arr[_random_index]);
    int _pivot=arr[_pivot_index];
    int pIndex=l;
    int i=l;
    int _count=0;
    while(i!=_pivot_index){
        if(arr[i]==_pivot){
            _count++;// This optimization is for the duplicate elements
        }
        if(arr[i]<=_pivot){
            _swap(&arr[i],&arr[pIndex]);
            pIndex++;
        }
        i++;
    }
    _swap(&arr[pIndex],&arr[_pivot_index]);
    return pIndex-(_count/2);
}
/*
Utility function for the random select
*/
int _random_select(int *arr,int l,int r,int k){
    
    if(k>0 && k<=(r-l+1)){
    int pIndex=_random_partition(arr,l,r);
    if(pIndex-l == k-1){
        return arr[pIndex];
    }
    else if(pIndex-l > k-1 ){
        return _random_select(arr, l, pIndex-1,k);
    }
    else{
        return _random_select(arr,pIndex+1,r,k-(pIndex-l+1));
    }
    }
    return INT_MAX;
}
 


int main(void){
int arr[]={12, 3, 5, 7, 4, 19, 26};
int N=sizeof(arr)/sizeof(arr[0]);
int k=5;
cout<<"The "<<k<<"smallest element is :"<<endl;
cout<<_random_select(arr,0,N-1,k);
    
return 0;    
}
