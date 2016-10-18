/*
@Shubham Sharma
-18/10/2016
*/

/*
 ------------------------Sequence Containers------------------------------------

STL sequence Containers:
==> vector , list , forward_lists , deque, array

1. vectors and arrays (contigous) provides better cache capabilities
as there are a lot of cache hits due to temporal locality 
while lists and maps are not contigous so traversing them causes lots of cache 
misses.

2. The most important function of the lists that other datatypes cannot do:

list1.splice(iter,list2,list2_itr_start,list2_itr_end); O(1)
many developers uses list for this function only

3. Lists take memory for the prev and next pointers so they waste memory 
and when they are transferred to memory some amount of the cache memory is 
also taken by the prev and the next pointers in cache so they are cache non-friendly

 
*/

#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<algorithm>
using namespace std;

int main(void){
    //-------------------------Vector
    vector<int> V;
    V.push_back(8);
    V.push_back(10);
    V.push_back(12);
    
    cout<<V[1]<<endl; // does not apply range checks
    cout<<V.at(1)<<endl; // apply range checks. throws range_error exception at out of range_error
    
    for(int i=0;i<V.size();++i){
        cout<<V[i]<<" ";
    }
    cout<<endl;
    for(vector<int>::iterator iter=V.begin();iter!=V.end();++iter){
        cout<<*iter<<" ";
    }
    cout<<endl;
    for(it : V){   ///only for c++ 11 onwards
        cout<<it<<" ";
    }
    cout<<endl;
    //Vector is a dynamically allocated contigous memory in heap
    int *p=&V[0];p[1]=6;
    
    //common APIs provided by all Containers
    bool is_empty=V.empty();
    int _size=V.size();
    vector<int> vec2(V);// copy constructor
    V.clear(); // clears all items in container ; V.size()==0 
    vec2.swap(V); // swaps the contents between the two Containers
    
    /*
    Properties Of vectors:
    1. fast insert/remove at the end O(1).
    2. slow insert in the middle or in the beginning O(n).
    3. slow search O(n) if unsorted
    */
    
    //------------------------------DEQUE-------------------------------------
    
    //vector can only grow at the end while deque can grow both_ways
    deque<int> D={5,7,9};
    D.push_back(16);
    D.push_front(12);
    
    cout<<D.at(3)<<endl;// apply range check 
    
    // deque is also random access
    
    for(it : D){
        cout<<it<<" ";
    }
    cout<<endl;
    
    /*
    Properties:
    1. fast insert/remove at the beginning/end O(1)
    2. slow insert/remove at the middle O(n)
    3. slow search O(n)
    */
    
    //-----------------------------List---------------------------------------
    
    // A list is a doubly linked list
    list<int> L={3,7,8};
    L.push_back(4);
    L.push_back(9);
    L.push_front(6);
    
    list<int>:: iterator iter= find(L.begin(),L.end(),4); // Find is a universal algorithm that searches like (cont.start,cont.end,key);
    L.insert(iter,2);// this will insert 2 just before iter , This is very fast insertion O(1)
    iter++; // *iter==9
    if(iter!=L.end()){
    L.erase(iter);
    }
    else{
        cout<<"You are already on the last"<<endl;
    }
    cout<<endl;
    for(it : L){
        cout<< it<<" ";
    }
    cout<<endl;
    
    // most important function of lists
    
    //L.splice(itr,L2,iter_L2_start,iter_L2_end); //O(1)
    
    /*
    Properties:
    1. fast insert/remove at any place beg,middle,end O(1)
    2. slow search O(n)
    3. no random access like deque,array , vector [] operator
    */
    
    //-----------------------Forward List------------------------------- 
     // It is just the singly linked list with one pointer to the next element
     
     //----------Array------------------------------------------------------
     array<int,3> a={1,2,3,4};// The size is fixed to 3
     array<int,4> b={4,5,7};// The size is fixed to 4
     
     // These functions provide .size(), .swap(), .begin(), apis 
     // but they suffer from the fact that a and b are considered as the 
     // different types as they have different sizes . It's not practical to use them.
     
    return 0;
}
