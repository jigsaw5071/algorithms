/*
-By Shubham Sharma
:16-09-2016
*/
/*
 This algorithm involves maintaining max heap of all elements that are less than effective median and min heap of all
 elements that are greater than effective median
 
 At any time the time complexity of the median is O(1)
 and time complexity for adjsting the heaps is O(logk)
*/
#include<bits/stdc++.h>
using namespace std;

/*
utility function for swap
*/
void _swap(int *a,int *b){
int temp=*a;
*a=*b;
*b=temp;
}

/*
Utility function for the min_heapify
*/
void _min_heapify(vector<int>& V,int i){
int _size=V.size();
int l=2*i+1;
int r=2*i+2;
int smallest=i;
if(l<_size && V[l]<V[i]){
smallest=l;
}
if(r<_size && V[r]<V[smallest]){
smallest=r;
}
if(i!=smallest){
_swap(&V[i],&V[smallest]);
_min_heapify(V,smallest);
}
}

/*
Utility function for the max_heapify
*/
void _max_heapify(vector<int>& V,int i){
int _size=V.size();
int l=2*i+1;
int r=2*i+2;
int largest=i;
if(l<_size && V[l]>V[i]){
largest=l;
}
if(r<_size && V[r]>V[largest]){
largest=r;
}
if(i!=largest){
_swap(&V[i],&V[largest]);
_min_heapify(V,largest);
}
}

/*
Priority queue operation to xecute the increase key operation
*/
void _increase_key(vector<int> &V,int i){
while(i>0 && V[(i-1)/2]<V[i]){
_swap(&V[(i-1)/2],&V[i]);
i=(i-1)/2;
}
}

/*
Priority queue operation to xecute the decrease key operation
*/
void _decrease_key(vector<int> &V,int i){
while(i>0 && V[(i-1)/2]>V[i]){
_swap(&V[(i-1)/2],&V[i]);
i=(i-1)/2;
}
}

/*
Utility function for maintaining the min and the max using the heap
*/
void _median_stream(vector<int>& _min_heap,vector<int>& _max_heap,const int _count,float& _median,const int _new_number){

if(_count & 1){
//count is odd
if(_new_number > _min_heap[0]){
_median=(float)_min_heap[0];
_min_heap[0]=_new_number;
_min_heapify(_min_heap,0);
}
else if(_new_number < _max_heap[0]){
_median=(float)_max_heap[0];
_max_heap[0]=_new_number;
_max_heapify(_max_heap,0);
}
else{
_median=(float)_new_number;
}
}
else{
//count is even
int _old_median=(int)_median;
if(_new_number > _min_heap[0]){
_median=(_median+(float)_min_heap[0])/2.0;
if((float)_old_median<=_median){
_max_heap.push_back(_old_median);
_increase_key(_max_heap,_max_heap.size()-1);
_min_heap.push_back(_new_number);
}
else{
_min_heap.push_back(_old_median);
_decrease_key(_min_heap,_min_heap.size()-1);
_min_heap.push_back(_new_number);
}
}

else if(_new_number < _max_heap[0]){
_median=(_median+(float)_max_heap[0])/2.0;
if(float(_old_median)<= _median){
_max_heap.push_back(_old_median);
_increase_key(_max_heap,_max_heap.size()-1);
_max_heap.push_back(_new_number);
}
else{
_min_heap.push_back(_old_median);
_decrease_key(_min_heap,_min_heap.size()-1);
_max_heap.push_back(_new_number);
}
}

else{
_median=(_median + float(_new_number))/2.0;
if(float(_old_median)<= _median){
_max_heap.push_back(_old_median);
_increase_key(_max_heap,_max_heap.size()-1);
}
else{
_min_heap.push_back(_old_median);
_decrease_key(_min_heap,_min_heap.size()-1);
}
if(float(_new_number)>=_median){
_min_heap.push_back(_new_number);
_decrease_key(_min_heap,_min_heap.size()-1);
}
else{
_max_heap.push_back(_new_number);
_increase_key(_max_heap,_max_heap.size()-1);
}
}

}



}


int main(void){
vector<int> _min_heap,_max_heap;
float _median=0.0;
int _count=0;
while(1){
cout<<"Please Select 1. Insert New Number   2. Show current Median   3.  Quit   "<<endl;
int _choice;
cin>>_choice;
if(_choice==1){
cout<<"Please Insert the new Number: ";
int _new_number;
cin>>_new_number;
_count++;
if(_count==1){
_median=(float)_new_number;
}
else if(_count==2){
_min_heap.push_back((_median>_new_number)?(int)_median:_new_number);
_max_heap.push_back((_median<_new_number)?(int)_median:_new_number);
_median=(_median+(float)_new_number)/2.0;
}
else{
/*
Main Driving Logic
*/

_median_stream(_min_heap,_max_heap,_count,_median,_new_number);

}
}
else if(_choice==2){
if(_count==0){
cout<<"The stream is empty .. Please Enter a number into it...."<<endl<<endl;
}
else{

cout<<endl<<"The current median is "<<_median<<endl<<endl;
}
}
else if(_choice==3){
break;
}
else{
cout<<"You Selected a wrong choice . Please Try Again..........."<<endl<<endl;
}
}
return 0;
}
