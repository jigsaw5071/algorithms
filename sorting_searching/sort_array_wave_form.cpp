/*
-By Shubham Sharma
-06-06-2016
*/
// this algorithm takes O(N) time and works on the paradigm of even indexes or odd indexes
// This algorithm works in O(nlogn) if we sort the array and replace the adjacent elements.
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
sorts the array in wave form with arr[0]>=arr[1]<=arr[2]>=arr[3]..........
*/
void _sort_wave_form(int *arr,const int N){
if(N==1){
return ;    
} 
for(int i=1;i<N;i=i+2){
int smallest=i;    
if(i-1>=0){
smallest=(arr[i]<arr[i-1])?i:i-1;    
}
if(i+1<=N-1){
smallest=(arr[i+1]<arr[smallest])?i+1:smallest;    
}
if(smallest!=i){
_swap(&arr[smallest],&arr[i]);    
}
    
}
    
}

int main(void){
int arr[]={10, 5, 6, 3, 2, 20, 100, 80};
int N=sizeof(arr)/sizeof(arr[0]);

_sort_wave_form(arr,N);
for(int i=0;i<N;++i){
    cout<<arr[i]<<" ";
}
cout<<endl;

    
return 0;    
}
