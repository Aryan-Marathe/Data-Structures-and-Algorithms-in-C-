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

void reverse_array(vector<int> &arr,int i,int j){
    if(i>=j){
        return;
    }
    swap(arr[i],arr[j]);
    reverse_array(arr,i+1,j-1);
}

bool check_palindrome(string str,int i,int j){
    if(i>=j){
        return true;
    }
    else if(str[i]!=str[j]){
        return false;
    }
    else{
        return check_palindrome(str,i+1,j-1);
    }
}

int fibonacci_num(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return fibonacci_num(n-1)+fibonacci_num(n-2);
}

void print_subsequences(int idx,vector<int> &ds,vector<int> &arr,int n){

    if(idx==n){
        for(auto it : ds){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }

    //take or pick the perticular index into the subsequence
    ds.push_back(arr[idx]);
    print_subsequences(idx+1,ds,arr,n);
    ds.pop_back();

    //not pick condition this element is not added to your subsequence
    print_subsequences(idx+1,ds,arr,n);
}
int main(){

    // int n;
    // cout<<"enter the value of n : ";
    // cin>>n;
    // print_name(1,n);

    // print_num(1,n);

    // print_num_reverse(1,n);

    // print_sum_param(n,0);
    // cout<<print_sum_func(n);

    // cout<<factorial_func(n);

    // vector<int> arr={1,2,3,4,5};
    // reverse_array(arr,0,4);
    // for(int i=0;i<arr.size();i++){
    //     cout<<arr[i]<<" ";
    // }

    // string s1="aabbaa";
    // string s2="aabcaa";
    // cout<<check_palindrome(s2,0,5);

    // cout<<fibonacci_num(7);

    vector<int> arr={3,1,2};
    int n=3;
    vector<int> ds;
    print_subsequences(0,ds,arr,n);

    

    return 0;
}