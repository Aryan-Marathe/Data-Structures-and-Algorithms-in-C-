#include<bits/stdc++.h>
using namespace std;

//objects are eneties in the real world
// Class is like a blueprint of the object
class Teacher{
  

    //Access Modifiers:-
    // 1] private = data and methods are only accessible in class { By default every class member is private }
    // 2] public = data and methods are only accessible in class
    // 3] protected = data and methods are accessible inside class and to its derived class 


    private:
    float salary;

    public:
    // properties OR attributes
    string name;
    string dept;
    string sub;

    // methods OR member functions

    void change_dept(string Newdpt){

        dept=Newdpt;
    }
    
    // setter fucntion -> these fucntions are used to set the values of private members of class
    void set_sal(float sal){
        salary=sal;
    }

    //getter fucntion -> these fuctions are used to get the values of private function of the class
    float get_sal(){
        return salary;
    }
};

int main(){

    //object creation syntax 
    //  { className obj_name; }
    Teacher t1;

    //assigning values to the attributes 
    //{ obj_name.attribute_name; }
    t1.name="aryan";
    t1.dept="CO";
    t1.sub="cpp";

    cout<<t1.name<<endl; //printing the value of the name 

    t1.set_sal(2345.664); //setting the value of salary through setter function
    cout<<t1.get_sal()<<endl; //getting the value of salary through getter fucntion

    return 0;
}