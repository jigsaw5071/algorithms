/*
-By Shubham Sharma
05-09-2016
*/

#include<bits/stdc++.h>
using namespace std;

/*
Utility function to swap the two values by reference
*/
void _swap(int *a,int *b){
int temp=*a;
*a=*b;
*b=temp;
}

/*A class representing the blueprint of the priority queue*/
class _priority_queue{
private:
vector<int> V;
//set of heap functions
int _get_size();
int _left_child(int);
int _right_child(int);
void _max_heapify(int);
int _get_parent(int);
public:
void _print();

// set of the priority queue functions
int _maximum_key();
void _increase_key(int ,int);
void _insert(int);
int _extract_max();
};

/*
This function is used to return the size of the heap
*/
int _priority_queue::_get_size(){
return V.size();
}

/*
This function is used to return the left child of the parent
*/
int _priority_queue::_left_child(int i){
return 2*i+1;
}

/*
This function is used to return the right child of the parent
*/
int _priority_queue::_right_child(int i){
return 2*i+2;
}

/*
This function returns the parent of the child i
*/
int _priority_queue::_get_parent(int i){
return (i-1)/2;
}

/*
This function is used to max_heapify the array
*/
void _priority_queue::_max_heapify(int i){
int l=_left_child(i);
int r=_right_child(i);
int _size=_get_size();
int largest=i;
if(l<_size && V[l]>V[i]){
largest=l;
}
if(r<_size && V[r]>V[largest]){
largest=r;
}
if(largest!=i){
_swap(&V[largest],&V[i]);
_max_heapify(largest);
}
}

/*
utility function to print the array
*/
void _priority_queue::_print(){
if(V.size()==0){
cout<<"The array is already empty"<<endl;
}
else{
for(int i=0;i<V.size();++i){
cout<<V[i]<<" ";
}
cout<<endl;
}
}

/*
Priority queue operation to return the maximum in O(1)
*/
int _priority_queue::_maximum_key(){
return (V.size()==0)?INT_MIN:V[0];
}

/*
Priority queue operation to xecute the increase key operation
*/
void _priority_queue::_increase_key(int i,int key){
if(key<V[i]){
cout<<"This is an error as this key is less than the current value"<<endl;
return ;
}
V[i]=key;
while(i>0 && V[_get_parent(i)]<V[i]){
_swap(&V[_get_parent(i)],&V[i]);
i=_get_parent(i);
}
}

/*
Priority queue operation to insert in the array
*/
void _priority_queue::_insert(int key){
V.push_back(INT_MIN);
_increase_key(V.size()-1,key);
}
/*
Priority queue function for the extract max
*/
int _priority_queue::_extract_max(){
if(V.size()==0){
cout<<"Array is already empty!"<<endl;
return INT_MIN;
}
int _max=V[0];
V[0]=V[V.size()-1];
V.pop_back();
_max_heapify(0);
return _max;
}


int main(void){
_priority_queue Q;
Q._insert(9);
Q._insert(13);
Q._insert(15);
cout<<Q._extract_max()<<endl;
Q._print();



return 0;
}
