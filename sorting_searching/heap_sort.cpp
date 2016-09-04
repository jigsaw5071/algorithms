#include<iostream>
using namespace std;


void _swap(int *a,int *b){
int temp=*a;
*a=*b;
*b=temp;

}

class Heap{
private:
int _size;
int *arr;

public:
Heap(int *_arr,int __size){
arr=_arr;
_size=__size;
}

int _get_size();
void print_array();
int _parent(int);
int _left_child(int);
int _right_child(int);
void _max_heapify(int,int);
void _min_heapify(int);
void _heap_sort();

};

int Heap::_get_size(){
return _size;
}
int Heap::_parent(int i){
return (i & 2)? (i/2):(i/2)-1;
};

int Heap::_left_child(int i){
return 2*i +1;
}
int Heap::_right_child(int i){
return 2*i+2;
}


void Heap::_min_heapify(int i){
int l=_left_child(i);
int r=_right_child(i);
int smallest=i;

if(l<_size && arr[l]<arr[i]){
smallest=l;
}
if(r<_size && arr[r]<arr[smallest]){
smallest=r;
}
if(smallest!=i){
_swap(&arr[i],&arr[smallest]);
_min_heapify(smallest);
}
}


void Heap::_max_heapify(int i,int array_size){
int l=_left_child(i);
int r=_right_child(i);
int largest=i;
if(l<array_size && arr[l]>arr[i]){
largest=l;
}
if(r<array_size && arr[r]>arr[largest]){
largest=r;
}
if(largest!=i){
_swap(&arr[i],&arr[largest]);
_max_heapify(largest,array_size);
}
}

void Heap::_heap_sort(){
if(_size==0){
cout<<"The array is empty"<<endl;
}
else{
for(int i=_size/2-1;i>=0;i--)
_max_heapify(i,_size);
for(int i=_size-1;i>0;i--){
_swap(&arr[0],&arr[i]);
_max_heapify(0,i);
}
}


}



void Heap::print_array(){
for(int i=0;i<_size;++i){
cout<<arr[i]<<" ";
}
cout<<endl;
}


int main(void){
int arr[]={42,2,75,3,104,5,6};
int N=sizeof(arr)/sizeof(arr[0]);
Heap H(arr,N);
H._heap_sort();
H.print_array();


return 0;
}
