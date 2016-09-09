/*
-By Shubham Sharma
:09-09-2016
*/

#include<iostream>
using namespace std;
// Solution of the diamong problem using the virtual keyword

//Notes:
/*
In general it is not allowed to call grandparent's constructor directly.
You need to call it through parent's constructor and using the virtual 
keyword.
*/
class Person{
public:
Person(int x){cout<<"Person's paramatrized constructor is called"<<endl;}
Person(){cout<<"Person's default constructor is called"<<endl;}
};

class Faculty:virtual public Person{
    public:
    Faculty(int x):Person(x){cout<<"Faculty constructor is called"<<endl;}
};

class Student:virtual public Person{
    public:
    Student(int x):Person(x){cout<<"Student class  is called"<<endl;}
};

class Ta:public Faculty,public Student{
    public:
    Ta(int x):Faculty(x),Student(x){cout<<"TA constructor is called"<<endl;}
};

int main(void){
Ta T(30);    
return 0;    
}
