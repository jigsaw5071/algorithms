/*
- By Shubham Sharma
-06-09-2016
*/
/*
Balanced Binary search trees would also have been used for the same purposes
as the insertion  and the deletio in BST is also O(logn). But heap is more efficient as get minimu is in o(logn)
and we don't require two pointers for left and right. We just need _size variable 
for Heap.
*/


#include<iostream>
using namespace std;


/*
Function to swap the two elements
*/
void _swap(int *a,int *b){
int temp=*a;
*a=*b;
*b=temp;
}

/*a utility blueprint of the class heap*/
class Heap{
private:
int *arr;
int _size;
public:
Heap(int *_arr,int N){
arr=_arr;    
_size=N;    
}

int _left_child(int);

int _right_child(int);

int _parent(int);

void _min_heapify(int);

void _print();

int _replace_min(int);

int _extract_min();

int _get_size();
    
};

/*
Function to get the left child of the node
*/
int Heap::_left_child(int i){
    return 2*i+1; 
}

/*
Function to get the right child of the node
*/
int Heap::_right_child(int i){
    return 2*i+2; 
}

/*
Function to get the parent of the node
*/
int Heap::_parent(int i){
    return (i-1)/2;
}

/*
Function to do the min-heapify subroutine
*/
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
    _min_heapify(smallest);//The worst case time complexity of this is O(logn)
}
}

/*
Function to print the array for debugging 
*/
void Heap::_print(){
    if(_size==0){
        cout<<"The array is already empty!"<<endl;
    }
    else{
        for(int i=0;i<_size;++i){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
}

/*
this returns the miniumum and replaces it with a new value and thus
maintans the heap property
*/
int Heap::_replace_min(int key){
    int _minimum=arr[0];
    arr[0]=key;
    _min_heapify(0);
    return _minimum;
    }
/*
it returns the minimum and also removes it from the original array
*/
int Heap::_extract_min(){
    int _minimum=arr[0];
    arr[0]=arr[_size-1];
    _size--;
    _min_heapify(0);
    return _minimum;
}  

/*
Function that returns the size of the heap
*/
int Heap::_get_size(){
    return _size;
}

/*
K way sort function
*/
void _k_way_sort(int *arr,int N,int K){
int *temp=new int[K+1];
for(int i=0;i<=K;++i){
    temp[i]=arr[i];
}
Heap H(temp,K+1); 
int i=((K+1) & 1)?(K+1)/2:((K+1)/2)-1;
while(i>=0){
H._min_heapify(i);
i--;
}
for(int j=K+1;j<N;j++){
    arr[j-K-1]=H._replace_min(arr[j]);
}
int _index=N-K-1;
while(H._get_size()!=0){
    arr[_index]=H._extract_min();
    _index++;
}

}


int main(void){
 int arr[]={2 ,6 , 3, 12, 56, 8};
 int K=3;
 int N=sizeof(arr)/sizeof(arr[0]);
 _k_way_sort(arr,N,K);
 for(int i=0;i<N;++i){
    cout<<arr[i]<<" ";
}
cout<<endl;   
    
return 0;    
}
