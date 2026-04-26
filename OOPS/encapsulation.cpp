#include<bits/stdc++.h>
using namespace std;

// Encapsulation is wrapping up of the data and functions in a single unit called class 
// Used in data hiding { hiding sensitive information by using private keyword }

class Bank_sys{

    private:
    // data hinding by using private keyword
    string password;
    float acc_balance; 

    public:
    string acc_name;
    string acc_number;

    void set_balance(float balance){
        acc_balance=balance;
    }

    float get_balance(){
        return acc_balance;
    }
};

int main(){

    Bank_sys b1;
    b1.acc_name="xyz";
    b1.acc_number="23456mh1";
    b1.set_balance(234567); //setting the balance
    cout<<b1.get_balance(); //getting the balance 
    return 0;
}