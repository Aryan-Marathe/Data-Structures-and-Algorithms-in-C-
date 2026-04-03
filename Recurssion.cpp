#include<bits/stdc++.h>
using namespace std;

void print_name(int i,int n)
{
    if(i>n){
        return;
    }
    cout<<"aryan"<<endl;
    print_name(i+1,n);
}

void print_num(int i, int n){

    if(i>n){
        return;
    }

    cout<<i<<endl;
    print_num(i+1,n);
}

void print_num_reverse(int i,int n){

    if(i>n){
        return;
    }

    print_num_reverse(i+1,n);
    cout<<i<<endl;
}

void print_sum_param(int i,int sum){

    if(i<1){
        cout<<sum;
        return;
    }

    print_sum_param(i-1,sum+i);

    
}

int print_sum_func(int n){

    if(n==0){
        return 0;
    }

   return n+print_sum_func(n-1);
}


int factorial_func(int n){
    if(n==1){
        return 1;
    }

    return n*factorial_func(n-1);
}

int reverse_array(){
    
}

int main(){

    int n;
    cout<<"enter the value of n : ";
    cin>>n;
    // print_name(1,n);

    // print_num(1,n);

    // print_num_reverse(1,n);

    // print_sum_param(n,0);
    // cout<<print_sum_func(n);

    // cout<<factorial_func(n);


    return 0;
}