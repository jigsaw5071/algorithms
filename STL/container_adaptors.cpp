/*
@Shubham Sharma
-18/10/2016
*/

/*
 ------------------------Container adaptors------------------------------------
LIFO : Stack push(),pop(),top()
FIFO : queue push(),pop(),top(),front()
Priority queue: push(),pop(),top()

Array based pointers invalidates pointers

Eg: vector<int> V={1,2,3};
int *p=&V[0];
vec.insert(p,2);
cout<<*p;//error because the memory may be allocated to new V at different place
*/

#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main(void){
 stack <int> S;
 S.push(8);
 S.push(20);
 
 queue<int> Q;
 Q.push(8);
 Q.front();
   
  
   
    return 0;
}
