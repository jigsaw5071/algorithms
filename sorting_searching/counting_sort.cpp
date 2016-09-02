#include<iostream>
using namespace std;

int _max(int *arr,const int N){
int _result=arr[0];
for(int i=1;i<N;++i){
if(_result<arr[i]){
_result=arr[i];
}
}
return _result;
}

void _counting_sort(int *arr,const int N){
int _max_value=_max(arr,N);
int *_count=new int[_max_value+1];
int *result=new int[N];
for(int i=0;i<N;++i){
_count[arr[i]]++;
}
for(int i=1;i<=_max_value;++i){
_count[i]+=_count[i-1];
}
for(int i=0;i<N;++i){
result[_count[arr[i]]-1]=arr[i];
_count[arr[i]]--;
}
for(int i=0;i<N;++i){
arr[i]=result[i];
}
free(result);
free(_count);
}


int main(void){
int arr[]={17, 4, 7, 9, 8, 24, 2, 6};
int N=sizeof(arr)/sizeof(arr[0]);
_counting_sort(arr,N);
for(int i=0;i<N;++i){
cout<<arr[i]<<" ";
}
cout<<endl;
return 0;
}
