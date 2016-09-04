#include<bits/stdc++.h>
using namespace std;

//The Time complexity of this algorithm is O(N).
// The space cmplexity is O(1)

void _print_unsorted_array(int *arr,const int N){
int s=0,e=0;
for(int i=0;i<N-1;i++){
if(arr[i+1]<arr[i]){
s=i;
break;
}
}
if(s==N-1){
cout<<"The following array is already sorted"<<endl;
return;
}
for(int i=N-1;i>0;i--){
if(arr[i]<arr[i-1]){
e=i;
break;
}
}
int _max=arr[s];
int _min=arr[s];
for(int i=s+1;i<=e;++i){
if(arr[i]>_max){
_max=arr[i];
}
if(arr[i]<_min){
_min=arr[i];
}
}
for(int i=s-1;i>=0;i--){
if(arr[i]>_min){

s=i;
}
else {
break;
}
}
for(int i=e+1;i<N-1;++i){
if(arr[i]<_max){
e=i;
}
else{
break;
}
}
cout<<"The array elemnts are unsorted from : "<<s<<" to "<<e<<endl;

}

int main(void){
int arr[]={0, 1, 15, 25, 6, 7, 30, 40, 50};
int N=sizeof(arr)/sizeof(arr[0]);
_print_unsorted_array(arr,N);
return 0;
}
