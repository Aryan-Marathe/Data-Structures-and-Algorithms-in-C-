#include<bits/stdc++.h>
using namespace std;

int extract_digits(int n){

    while(n>0){
        cout<<n%10;
        n=n/10;
    }

    return n;
}

int count_digits(int n){

    int cnt=0;
    while(n>0){
        int last_digit=n%10;
        cnt++;
        n=n/10;
    }

    return cnt;

}

int print_reverse_num(int n ){

    int rev_num=0;
    while(n>0){

        int lastdigit=n%10;
        n=n/10;
        rev_num=(rev_num*10)+lastdigit;
    }
    return rev_num;
}


void paindrome(int n,int rev_num){
    //check if "n" in extract digits and "rev_num" in print rev_num is same or not 
}

int check_armstrong_num(int n){
    int duplicate=n;
    int num=0;
    while(n>0){
        int last_digit=n%10;
        // cout<<last_digit<<endl;
        num=num+(last_digit*last_digit*last_digit);
        n=n/10;
    }
     
    if (duplicate==num){
        return true;
    }
    else{
        return false;
    }
    
}

int print_dovisors(int n){

    for(int i=1;i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
}


bool check_prime(int n){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cnt++;
        }
    }

    if(cnt==2){
        return true;
    }
    else{
        return false;
    }
}


int GCD_HCF(int a, int b){

    while (a>0 && b>0)
    {
        if(a>b){
            a=a%b;
        }
        else{
            b=b%a;
        }
    }

    if(a==0){
        return b;
    }

    else{
        return a;
    }
    
}


int main(){

    // extract_digits(22467);

    // cout<<count_digits(334516)<<endl;
    // cout<<count_digits(3345)<<endl;
    // cout<<count_digits(516)<<endl;
    // cout<<count_digits(3)<<endl;

    // cout<<print_reverse_num(446678)<<endl;
    // cout<<print_reverse_num(23600)<<endl;

    // check_armstrong_num(371);
    // cout<<check_armstrong_num(371)<<endl;
    // cout<<check_armstrong_num(1634)<<endl;
    // cout<<check_armstrong_num(35)<<endl;

    // print_dovisors(36);

    cout<<check_prime(11)<<endl;
    cout<<check_prime(9)<<endl;
    cout<<check_prime(3)<<endl;

    
    return 0;

}