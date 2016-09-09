/*
-By Shubham Sharma
:09-09-2016
*/
#include<iostream>
using namespace std;
//--------------------very important concept
// Giving More restrictive access to the derived class

/* case 2 runs fine as the fun is public for the base class
but the binding is done at the run time not at the compile time.
So as the fun() is public in the base class so at the compile time
it would not produce any error and during the run time there is no 
check for the access specifiers.
This functionality is not provided in java
*/
class Base{
    public:
    virtual void fun(){cout<<"This is the fun of the base class"<<endl;}
};

class Derived:public Base{
    private:
    void fun(){cout<<"This is the fun of the derived class"<<endl;}
    };

int main(void){
    
    //case 1
    /*
    Derived D;
    D.fun();      This causes error as fun is private accessible
    */
   //case 2 
    Base *B =new Derived;
    B->fun();// this actually runs fine
    delete B;
    
return 0;    
}
