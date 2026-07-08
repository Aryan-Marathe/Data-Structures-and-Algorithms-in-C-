#include<bits/stdc++.h>
using namespace std;

string convert_to_binary(int n){
    string res="";
    while (n!=0)
    {   
        if(n%2==1){
            res+="1";
        }
        else{
            res+="0";
        }
        n=n/2;
    }

    reverse(res.begin(),res.end());
    return res;
    
}

int convert_to_decimal(string str){
    int n=str.size();
    int num=0;
    int power2=1;
    for(int i=n-1;i>=0;i--){
        if(str[i]=='1'){
            num=num+power2;
        }
        power2=power2*2;
    }
    return num;
}

/*

    x >> k = x/2^k  { right shift }
    x << k = x*2^k  { left shift }
*/

void swap_numbers(int a,int b){
    a=a^b;
    b=a^b; // ->b=(a^b)^b=a ---{ from step 1 }
    a=a^b; // ->a=(a^b)^a=b ---{ from step 2 }

    cout<<a<<" "<<b;
}

bool check_set_or_not(int num,int idx){
    // UISNG LEFT SHIFT OPERATOR
    /*
    if(num & (1<<idx)!=0){
        return true;
    }
    else{
        return false;
    }
     */

    // USING RIGHT SHIFT OPERATOR

    if((num>>idx) & 1){
        return true;
    }
    else{
        return false;
    }
}  

int set_ith_bit(int num,int i){
    int new_num=((1<<i) | num);
    return new_num;
}

int clear_ith_bit(int num,int i){
    int new_num=(~(1<<i) & num);
    return new_num;
}

int toggle_ith_bit(int num,int i){
    int new_num=((1<<i) ^ num);
    return new_num;
}

int remove_last_set_bit(int num){
    return num & (num-1);
}

bool check_if_num_power_of2_or_not(int num){
    if((num & (num-1))==0){
        return true;
    }
    else{
        return false;
    }
}

int count_number_of_set_bits(int num){
    string str=convert_to_binary(num);
    int cnt=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='1'){
            cnt+=1;
        }   
    }
    return cnt;
}
int main(){

    // cout<<convert_to_binary(9);

    // cout<<convert_to_decimal("111");

    // swap_numbers(1,3);

    // cout<<check_set_or_not(13,2);

    // cout<<set_ith_bit(9,2);

    // cout<<clear_ith_bit(13,2);
    
    // cout<<toggle_ith_bit(9,2);

    // cout<<remove_last_set_bit(84)<<'\n';

    cout<<count_number_of_set_bits(9);


    return 0;
}