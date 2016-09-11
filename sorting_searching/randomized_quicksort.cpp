/*
-By Shubham Sharma
:10-09-2016
:reference: Introductions To Algorithms (CLRS)
*/

#include<iostream>
#include<time.h>
using namespace std;

// This is regarded as the random sampling algorithm
// and it's expected running time is O(n log n )


/*
Utility function to swap the two elements by call by reference
*/
void _swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

/*
randomized Partition functions with the count optimization 
in case of the duplicates 
*/
int _randomized_partition(int *arr,const int l,const int r){
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
A randomized quickSort using tail call optimizations
and reducing the stack frame calls upto O(log n)
*/

void _randomized_quickSort(int *arr,int l,int r){
    while(l<r){
    int pIndex=_randomized_partition(arr,l,r);
    if(pIndex-l > pIndex-r){
        _randomized_quickSort(arr,pIndex+1,r);
        r=pIndex-1;
    }
    else{
        _randomized_quickSort(arr,l,pIndex-1);
        l=pIndex+1;
    }
    }
}

int main(void){
int arr[]={47,25,2,84,45,91,27};
int N=sizeof(arr)/sizeof(arr[0]);
_randomized_quickSort(arr,0,N-1);
for(int i=0;i<N;++i){
    cout<<arr[i]<<" ";
}
cout<<endl;
return 0;    
}
