/*
-By Shubham Sharma
:16-09-2016
*/

/*
-----Function Templates:

1.This entails the importance of templates in avoiding the code reduncdancy
that we have to write.
2.You dont need to specifically maintain the data type in case of the functions.The 
compiler automatically gets the data type of the input only in case of the 
functions.
3. One actual problem that we face with templates is that there is the problem of code 
bloat. Once there are various data types there is a separate code for each data type 
thus bloating the code.

---------------Class Templates:
1. Compiler cannot infer datatype from the parameter in case of the class template 
as it does in the function templates. You need to specify the datatype of the
parameters in class templates.

--------The typename keyword can always be replaced with the class keyword

------------------More than one typename in the templates
Eg. template<class U,class V=char> This is the default argument


-----Difference between templates and function overloading
-Both are the examples of the polymorphism features of the oops.Function overloading 
is used when multiple functions do similar things, while templates are used when 
multiple functions use simiar things.

------------How Templates work
- templates expand at the compile time. This is similar to the macros.The difference is 
Compiler does type checking before the type expansion.The final compiled code may conatins
multiple copies of the same code;

-----------Non type parameters are also available in the functionality 
of the templates but they must be constant and the compiler must know them at the
 compile time
*/

#include<iostream>
#include<vector>
using namespace std;

/*
utility template for function square
*/
template<typename T>
T _get_square(const T& x ){
    return x*x;
}

/*
utlity template for class
*/
template<typename T>
class _stack{
    private:
    vector<T> V;
    int _size;
    public:
    _stack(int _size):_size(_size){}
    int _get_size();
    void _push(T);
    void _print();
};
/*
utility function to get the size of the generic stack
*/
template<typename T>
int _stack<T>::_get_size(){
    return _size;
}

/*
utility function for the push of the generic stack
*/
template<typename T>
void _stack<T>::_push(T x){
    V.push_back(x);
    _size++;
}

/*
Utility function to print the stack
*/
template<typename T>
void _stack<T>::_print(){
    if(_size==0){
        cout<<"The stack is already empty "<<endl;
    }
    else{
        for(int i=_size-1;i>=0;i--){
            cout<<V[i]<<" ";
        }
        cout<<endl;
    }
}

/*
utility template with more than one arguement
*/
template<class T,class U=char>//default arguments
class _multiple_arguments{
    private:
    T x;
    U y;
    public:
    _multiple_arguments(){
        cout<<"Constructer called"<<endl;
    }
};


int main(void){
//calling the function template
cout<<_get_square<int>(5)<<endl;
cout<<_get_square<float>(5.25)<<endl;

//calling the function of the classt template
_stack<int> S(0);
S._push(5);
S._push(7);
S._push(12);
S._print();
_stack<double> V(0);
V._push(5.5);
V._push(7.5);
V._push(12.5);
V._print();

//calling the template with the _multiple_arguments
_multiple_arguments<int ,char> M;
return 0;    
}