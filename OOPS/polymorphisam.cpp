#include <bits/stdc++.h>
using namespace std;

/* Polymorphism is the ability of objects to take the different forms or behave in different ways 
depending in the context in which they are used.

compile time polymorphism ex. constructor overloading, function overloading

run time polymorphism  ex. function overrridng { parent and child both contain the same function with different implementation.}
                                                { parent class function is said to be overriden.}
*/

class Print{

    // function overloading { same name but different parameters }
    public:

    void show(int x){
        cout<<"int : "<<x<<endl;
    }

    void show(char x){
        cout<<"char : "<<x<<endl;
    }
};

// function overrridng

class parent{
 public:

 void show(){
    cout<<"parent class"<<endl;
 }

 virtual void out(){
        cout<<"from parent class "<<endl;
 }
};

class child : public parent{
    public:
    //here parent class function is overrided
    void show(){
        cout<<"child class"<<endl;
    }

    void out(){
        cout<<"from child class "<<endl;
 }
};

// A virtual fucntionn is a member function that you expect to be redefined in derived class 

/*
  PROPERTIES

  1]virtual function are Dynamic in nature 
  2]Defined by the "virtual" keyword inside the parent class and always declared with abse class
  and overrriden in child class.
  3]A virtual function called during runtime.
*/

int main(){

    Print p1;
    p1.show(3);
    p1.show('c');

    child c1;
    c1.show();
    c1.out();

    parent obj;
    obj.out();
    return 0;
}