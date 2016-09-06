/*
-By Shubham Sharma
-06-09-2016
*/
// Iterative quicksort is same as the recursive quicksort
// But it minimizes the overheads of the function stack frames
//But it uses the auxillary space for the stack of O(N)
// all the optimizations of the recursive quicksort can also be applied to this
#include<iostream>
using namespace std;

/*
swap function
*/
void _swap(int *a,int *b){
int temp=*a;
*a=*b;
*b=temp;
}
/*
Partition function same as the recursive quicksort
*/
int _partition(int *arr,int l,int r){
int pivot=arr[r];
int pivot_index=r;
int i=l;
int pIndex=l;
while(i!=pivot_index){
if(arr[i]<=pivot){
    _swap(&arr[i],&arr[pIndex]);
    pIndex++;
}
i++;
}
_swap(&arr[pIndex],&arr[pivot_index]);
return pIndex;
    }


/*
Iterative quicksort function
*/
void _iterative_quickSort(int *arr, int l, int r){
int stack[r-l+1];
int top=-1;
stack[++top]=l;
stack[++top]=r;
while(top>=0){
 r=stack[top--];
 l=stack[top--];
int pIndex=_partition(arr,l,r);
if(pIndex+1< r){// this step is to ensure that the side array of pIndex is greater than 1
    stack[++top]=pIndex+1;
    stack[++top]=r;
}
if(pIndex-1 > l){
stack[++top]=l;
stack[++top]=pIndex-1;
}
}
}



int main(void){
int arr[]={4, 3, 5, 2, 1, 3, 2, 3};
int N=sizeof(arr)/sizeof(arr[0]);
_iterative_quickSort(arr,0,N-1);
for(int i=0;i<N;++i){
cout<<arr[i]<<" ";    
}
cout<<endl;
return 0;    
}
