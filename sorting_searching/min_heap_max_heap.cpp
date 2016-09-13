/*
-By Shubham Sharma
:13-09-2016
:reference-CLRS
*/

/*
This question is used to convert minheap to max_heap
The crux of this question is assume minheap as normal array 
 and make the max heap out of it in O(n) time
*/
#include<iostream>
#include<vector>
using namespace std;

/*
Utility function for the swap
*/
void _swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

/*class bluePrint for heap*/
class Heap{
  private:
  int _left_child(int);
  int _right_child(int);
  int _parent(int);
  void _max_heapify(vector<int>&,int);
  void _min_heapify(vector<int>&,int);
  public:
  void _print(vector<int>&);
  void _build_min_heap(vector<int>&);
  void _build_max_heap(vector<int>&);
  
};


/*
Utility function to find the left child of the parent
*/
int Heap::_left_child(int i){
    return 2*i+1;
}

/*
Utility function to find the right child of the parent
*/
int Heap::_right_child(int i){
    return 2*i+2;
}

/*
Utility function to find the parent node of the child
*/
int Heap::_parent(int i){
    return (i-1)/2;
}

/*
Utility function to max_heapify the heap
*/
void Heap::_max_heapify(vector<int> &V,int i){
    int l=_left_child(i);
    int r=_right_child(i);
    int largest=i;
    int _size=V.size();
    if(l<_size && V[l]>V[i]){
        largest=l;
    }
    if(r<_size && V[r]>V[largest]){
        largest=r;
    }
    if(i!=largest){
        _swap(&V[largest],&V[i]);
        _max_heapify(V,largest);
    }
    
}

/*
Utility function to min_heapify the heap
*/
void Heap::_min_heapify(vector<int> &V,int i){
    int l=_left_child(i);
    int r=_right_child(i);
    int smallest=i;
    int _size=V.size();
    if(l<_size && V[l]<V[i]){
        smallest=l;
    }
    if(r<_size && V[r]<V[smallest]){
        smallest=r;
    }
    if(i!=smallest){
        _swap(&V[smallest],&V[i]);
        _max_heapify(V,smallest);
    }
    
}

/*
Utility function wrapper to call the min_heap in O(n) time
*/
void Heap::_build_min_heap(vector<int>& V){
    int n=V.size();
    int k=(n/2)-1;
    while(k>=0){
        _min_heapify(V,k);
        k--;
    }
    
}

/*
Utility function wrapper to call the max_heap in O(n) time
*/
void Heap::_build_max_heap(vector<int>& V){
    int n=V.size();
    int k=(n/2)-1;
    while(k>=0){
        _max_heapify(V,k);
        k--;
    }
    
}

/*
utility function to print the array
*/
void Heap::_print(vector<int>& V){
    int n=V.size();
    for(int i=0;i<n;++i){
        cout<<V[i]<<" ";
    }
    cout<<endl;
}

int main(void){
    int arr[]={1,24,2,7,8,5,29,34};
    int N=sizeof(arr)/sizeof(arr[0]);
    vector<int> V(arr,arr+N);
    Heap H;
    H._print(V);
    H._build_min_heap(V);
    H._print(V);
    H._build_max_heap(V);
    H._print(V);
    
    return 0;
}
