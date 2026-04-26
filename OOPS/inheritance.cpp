#include<bits/stdc++.h>
using namespace std;

class person{

    public:
    string name;
    int age;

    person(string person_name,int person_age){
        cout<<"parent constructor"<<endl;

        this->name=person_name;
        this->age=person_age;
    }

    ~person(){
        cout<<"parent destructor"<<endl;
    }

};

class student : public person{

    public:

    int rollno;

    student(string name,int age,int student_roll) : person( name,age){
        cout<<"child constructor "<<endl;
        this->rollno=student_roll;
        }

    ~student(){
        cout<<"child destructor"<<endl;
    }

    void getinfo(){
        cout<<"name : "<<name<<endl;
        cout<<"age : "<<age<<endl;
        cout<<"rollno : "<<rollno<<endl;
    }
};


// TYPES OF INHERITANCE 

/*

SINGLE INHERITANCE ->

              PARENT CLASS
                |
              CHILD CLASS

MULTILEVEL INHERITANCE ->

             PARENT CLASS 1
                |
             PARENT CLASS 2
                |
             CHILD CLASS

MULTIPLE INHERITANCE ->

    PARENT CLASS 1   PARENT CLASS 2
            \          /
            CHILD CLASS

    SYNTAX->

        class child_class_name : public parent class 1, public parent class 2 {

        }

HIRARCHIAL INHERITANCE -> 

             PARENT CLASS
             /         \
    CHILD CLASS1    CHILD CLASS 2

    SYNTAX -> 

    class child_class1_name : public parent_class_name{
    
    };

    class child_class2_name : public parent_class_name{
    
    }

HYBRID INHERITANCE -> { COMBINATION OF ALL INHERITANCE }
*/
int main(){

    student s1("aryan",21,123);

    s1.getinfo();
    return 0;
}