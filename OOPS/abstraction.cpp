#include<bits/stdc++.h>
using namespace std;

/*
Abstraction is hiding all uncessary details and showing only the important parts

Pure virtual function -> a virtual function which has value 0.

if a class has Pure virtual function then it automatically become abstract class.

Abstract classes->

1]abstract classes are used to provide a base class from which other classes can be derived.
2]they cannot instantiated and are meant to be inherited.
3]abstarct classes are typically used to define an interface for derived classes.

Stactic variable and static function ->

variables are declared as static in a function are created and initialized for the lifetime of the prgram.

static variables in a class are created and initialized once. they are shared by all the objects of class.

*/

class shape{
     virtual void draw()=0; //pure virtual function 
};

class circle{

    public:
    void draw(){
        cout<<"drawing a circle"<<endl;
    }
};


void fun(){
    static int x=0;
    cout<<" x="<<x<<endl;
    x++;
}

class A{
    public:
    int x=0;

    void inc(){
        x=x+1;
    }
};

int main(){

    circle c1;
    c1.draw();

    fun(); 
    fun(); 
    fun(); 

    A obj;
    cout<<obj.x<<endl;
    obj.inc();
    cout<<obj.x<<endl;
    return 0;
}