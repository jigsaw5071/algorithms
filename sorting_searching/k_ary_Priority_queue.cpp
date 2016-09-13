/*
-By Shubham Sharma
:13-09-2016
*/

/*
K-ary heaps find efficiency in algorithms where increase_key/decrease_key
function prevails over extract_max/min and delete routines.
1. It's height is O(log n / log k)
2. It's max/min heapify is O(k * (log n / log k)
3. Build heap is O(n)
4. Increase/decrease key is fastest O(log n / log k).
5. Extract Max/Min is slow o(k* (log n/log k))
6. K-ary heaps provide better cache behavior than the binary heaps which allows
them to run more quickly
#7.Heap Sort and quick sort are only favourable only for the random access variables
like vector ,array,etc especially heap sort
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/*
Utility function to swap the two values by reference
*/
void _swap(int *a,int *b){
int temp=*a;
*a=*b;
*b=temp;
}

/*A class representing the blueprint of the priority queue made with k-ary heap*/
class _priority_queue{
    private:
    vector<int> V;
    const int k;//const and reference member variables are only initialized through initializer list
    // set of heap utility functions
    int _get_size();
    int _child(int,int);
    int _parent(int);
    void _max_heapify(int );
    public:
    _priority_queue(int k): k(k) { } 
    void _print();
    void _increase_key(int ,int);
    void _insert(int);
    int _extract_max();
    int _get_maximum();
    
};

/*
utility function to get the size of the current array
*/
int _priority_queue::_get_size(){
    return V.size();
}

/*
utility function to get the i nth child of the i node 0<=i<=k-1
*/
int _priority_queue::_child(int i,int n){
    return k*i+n;
}

/*
utility function to get the parent of the ith child
*/
int _priority_queue::_parent(int i){
    return (i-1)/k;
}

/*utility function to print the current array*/
void _priority_queue::_print(){
    int n=V.size();
    if(n==0){
        cout<<"The array is already empty"<<endl;
    }
    else{
        for(int i=0;i<n;++i){
            cout<<V[i]<<" ";
        }
        cout<<endl;
    }
}

/*
Utility function to do the max_heapify in the key in O(k (log n /log k))
*/
void _priority_queue::_max_heapify(int i){
    int largest=i;
    int n=_get_size();
    for(int j=1;j<=k;++j){
        int _j_child=_child(i,j);
        if(_j_child < n && V[_j_child]>V[largest]){
            largest=_j_child;
        }
    }
    if(i!=largest){
        _swap(&V[i],&V[largest]);
        _max_heapify(largest);
    }
}

/*
Utility function to set up the increase key operation in O( log n / log k)
*/
void _priority_queue::_increase_key(int i,int key){
  if(key<V[i]){
 cout<<"This is an error as this key is less than the current value"<<endl;
 return ;
  } 
  V[i]=key;
  while(i>0 && V[_parent(i)]<V[i]){
      _swap(&V[_parent(i)],&V[i]);
      i=_parent(i);
  }
}

/*
Utility function to insert the value inside the array
*/
void _priority_queue::_insert(int key){
    V.push_back(INT_MIN);
    _increase_key(V.size()-1,key);
    
}

/*
utility function to get the maximum
Time complexity:O(1)
*/
int _priority_queue::_get_maximum(){
    return V[0];
}

/*
utility function for the extract max 
Time complexity : O(k * (log n /log k))
*/

int _priority_queue::_extract_max(){
    int n=V.size();
    if(n==0){
    cout<<"The array is empty"<<endl;
    return INT_MIN;
    }
    else{
        int _maximum=V[0];
        V[0]=V[n-1];
        V.pop_back();
        _max_heapify(0);
        return _maximum;
    }
    
    
}
int main(){
    _priority_queue P(3);
    P._insert(4);
    P._insert(5);
    P._insert(6);
    P._insert(7);
    P._insert(8);
    P._insert(9);
    P._insert(10);
    P._print();
    P._extract_max();
    P._print();
    
}
