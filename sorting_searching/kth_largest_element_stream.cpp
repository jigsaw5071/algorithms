/*
-By Shubham Sharma
:16-09-2016
*/

/*
This algorithm is used to find the kth largest element in the stream of the
numbers using min-heap data structure
At any time the time in extracting the kth maximum is O(1)

The time complexity in finding the kth largest element is O(logk) as the min-heapify subroutine runs
*/
#include<bits/stdc++.h>
using namespace std;

/*
utility subroutine for the swap
*/
void _swap(int *a,int *b){
int temp=*a;
*a=*b;
*b=temp;
}
/*
utility subroutines for min heap
*/
void _min_heapify(int i,int *arr,int _size){
int l=2*i+1;
int r=2*i+2;
int smallest=i;
if(l<_size && arr[l]<arr[i]){
smallest=l;
}
if(r<_size && arr[r]<arr[smallest]){
smallest=r;
}
if(i!=smallest){
_swap(&arr[i],&arr[smallest]);
_min_heapify(smallest,arr,_size);
}
}
/*
utility function to find the kth largest element in the array
*/
void _kth_largest_element(const int k){
int *arr=new int[k];
int _count=0;
while(1){
if(_count==0){
cout<<"Please Enter the first "<<k<<" numbers: ";
for(int i=0;i<k;++i){
cin>>arr[i];
_count++;
}
make_heap(arr,arr+k,[](const int &a,const int &b){return a>b;});
}
else{
cout<<" Please Select       1. quit  2. insert  3.show current "<<k<< " largest element "<<endl;
int _choice;
cin>>_choice;
if(_choice==1){
break;
}
else if(_choice==2){
cout<<endl<<"Please insert the new element: ";
int _new_element;
cin>>_new_element;
_count++;
if(_new_element>arr[0]){
arr[0]=_new_element;
_min_heapify(0,arr,k);
}
cout<<endl;
}
else if(_choice ==3){
cout<<"The "<<k<<"th largest element is "<<arr[0]<<endl<<endl;
}
else{
cout<<"You have made an Invalid Choice  . Please Try Again!...."<<endl<<endl;
}
}
}
delete [] arr;
}

int main(void){
    int k;
    cout<<"Please Select The Index That you want to maintain:"<<endl;
    cin>>k;
    _kth_largest_element(k);

return 0;
}
