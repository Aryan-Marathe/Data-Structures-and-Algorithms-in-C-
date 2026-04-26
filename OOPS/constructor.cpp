#include<bits/stdc++.h>
using namespace std;

/*
CONSTRUCTOR-> Constructor is a special method invoked automatically every time while object creation.
              It is used for initialization. Declare constructor always public.

PROPERTIES ->
1] same name as class name.
2] constructor does not have return type.
3] only called once(automatically), at object creation.
4] memeory allocation happens when constructor is called.

Single class can have multiple constructor give that there parameters should be different 
*/

class Bank_sys{

    private:
    string password;
    float acc_balance; 

    public:
    //Creating a self define constructor {non paramertized constructor}
    Bank_sys(){
        cout<<" I AM CONSTRUCTOR!!";
        acc_name="None"; //initializes all account names to None { By default } if not assigned specifically 
    }

    string acc_name;
    string acc_number;

    void set_balance(float balance){
        acc_balance=balance;
    }

    float get_balance(){
        return acc_balance;
    }
   
};


class Doctor{

    private: 
    double salary;

    public:

    string name;
    string specialization;
    int *years;

    //Creating a self define constructor {paramertized constructor}
    Doctor(string doc_name, string doc_specialization,double doc_sal,int years_count){

        // this is the special pointer in c++ that points to the current object 
        // syntax:- { this->property_name }
        this->name=doc_name;
        this->specialization=doc_specialization;
        this->salary=doc_sal;
        this->years=new int;
        *this->years=years_count;
    }
   
     //Creating a self define constructor {copy constructor}
     Doctor(Doctor &orgObj){

        /*
            Shallow Copy -> A shallow copy of na object copies all if the memeber values from one obejct to another.
            Deep Copy -> A deep copy on the other hand not only copies the member values but also makes copies of 
                         any dynamically allocated memory that the memebers point to.
        */
        cout<<"Custom copy constructor: ";
        this->name=orgObj.name;
        this->specialization=orgObj.specialization;
        this->salary=orgObj.salary;
    }


    // Destructor { frees the dynamicallly allocated memory allocated by constructor }
    ~Doctor(){
        cout<<"DELETE EVERYTHING ";
        delete years; 
    }

    void set_sal(double sal){
        salary=sal;
    }

    double get_sal(){
        return salary;
    }

    void getInfo(){
        cout<<"name : "<<name<<endl;
        cout<<"specialization : "<<specialization<<endl;
    }
};

int main(){

/*
    Bank_sys b1; // constructor gets called automatically
    cout<<endl;
    cout<<"first user->"<<endl; 
    b1.acc_name="xyz";
    b1.acc_number="23456mh1";
    b1.set_balance(234567); 
    cout<<"name : "<<b1.acc_name<<endl;
    cout<<"account balance : "<<b1.get_balance()<<endl;  

    Bank_sys b2; // created second user { without specifing the acc_name which defualt gets None value}
    cout<<endl;
    cout<<"second user->"<<endl;
    b2.acc_number="356b2455";
    b2.set_balance(456778);
    cout<<"name : "<<b2.acc_name<<endl;
    cout<<"account balance : "<<b2.get_balance()<<endl;
*/

    Doctor d1("xyz","ortho",234.67,9); //passing values to constructor
    // d1.getInfo();

    // Doctor d2(d1); // Copy constructor gets called (default) { Copy constructor is a special type of constructor used to copy properties of one object to another. }
    // d2.getInfo(); // comment the copy constructor 

    Doctor d3(d1); //Copy constructor gets called (custom)
    d3.getInfo();

    return 0;
}