#include<iostream>
using namespace std;

void __merge(int *arr,const int l,const int r,const int m){
int n1=m-l+1;
int n2=r-m;
int _left_array[n1];
int _right_array[n2];
for(int i=0;i<n1;i++){
_left_array[i]=arr[l+i];
}
for(int j=0;j<n2;++j){
_right_array[j]=arr[m+j+1];
}
cout<<endl<<endl;
int i=0;
int j=0;
int k=l;
while(i<n1 && j<n2){
if(_left_array[i]<=_right_array[j]){
arr[k]=_left_array[i];
i++;
k++;
}
else{
arr[k]=_right_array[j];
j++;
k++;
}
}
while(i<n1){
arr[k]=_left_array[i];
i++;
k++;
}
while(j<n2){
arr[k]=_right_array[j];
j++;
k++;
}
}

void _mergesort(int *arr,const int l,const int r){
if(l<r){
int mid=l+(r-l)/2;
_mergesort(arr,l,mid);
_mergesort(arr,mid+1,r);
__merge(arr,l,r,mid);

}
}

int main(void){
int arr[]={12, 11, 13, 5, 6, 7,2};
int N=sizeof(arr)/sizeof(arr[0]);
_mergesort(arr,0,N-1);
for(int i=0;i<N;++i){
cout<<arr[i]<<" ";
}
return 0;
}

