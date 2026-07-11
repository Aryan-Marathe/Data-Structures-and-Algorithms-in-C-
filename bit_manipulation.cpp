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

int minimun_number_bit_flips(int start, int goal){

    /*
    let start = 10 and end = 7
    10 -> 1010 and 7 ->0111
    1010
   ^0111
   ---------
    1101

    the number of set bits in the result are the number of bits that is required to flip 
    */

    int new_num=start ^ goal;
    int flips = count_number_of_set_bits(new_num);
    return flips;

}

void power_set(const vector<int>& nums) {
    int n = nums.size();
    int total = 1 << n;
    vector<vector<int>> ans;
    for (int mask = 0; mask < total; ++mask) {
        vector<int> subset;
        for (int j = 0; j < n; ++j) {
            if (mask & (1 << j)) subset.push_back(nums[j]);
        }
        ans.push_back(subset);
    }
    for (const auto& s : ans) {
        cout << "{";
        for (size_t k = 0; k < s.size(); ++k) {
            if (k) cout << ", ";
            cout << s[k];
        }
        cout << "}\n";
    }
}

int single_number(vector<int> nums){

    int XOR=nums[0];
    int n=nums.size();
    for(int i=1;i<n;i++){
        XOR=XOR^nums[i];
    }
    return XOR;
}

int single_number_II(vector<int> nums){

    /*
    
    let vector be { 5,5,5,6,4,4,4}
    1]-> convert each number to binary
columnNumber:210

        5 -> 101
        5 -> 101
        5 -> 101
        6 -> 110
        4 -> 100
        4 -> 100
        4 -> 100

    2]-> check for each column if its number of set bits are in multiople of 3

        column 0 -> 3 set bits
        column 1 -> 1 set bit
        column 2 -> 7 set bits

    3]-> if number of set bits are in multiple of 3 do not set them in answer 
         else set the bit 
         
         ans = 110 { which is 6}
    */

    // int ans=0;
    int n=nums.size();
    // for(int bitIndex=0;bitIndex<32;bitIndex++){
    //     int cnt=0;
    //     for(int i=0;i<n;i++){
    //         if(nums[i] & (1U<<bitIndex)){
    //             cnt++;
    //         }
    //     }
    //     if(cnt % 3 != 0){
    //         ans = ans | (1U<<bitIndex);
    //     }
    // }
    // return ans;


    // APPROCH 2 -> 

     /*
     1] -> sort the array
     2] -> start form the 1st element of the array
     3] -> check for arr[i]==arr[i-1]
     4] -> if true do i+=3
           else return arr[i-1] is our ansewer
     5] -> if array is traversed completely ans no match found then last elemnet is our answer 
     */

    //  int ans=0;
    //  sort(nums.begin(),nums.end());
    //  for(int i=0;i<n;i+=1){
    //     if(nums[i]!=nums[i-1]){
    //         return nums[i-1];
    //     }
    //  }
    //  return nums[n-1];



     
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

    // cout<<count_number_of_set_bits(9);

    // cout<<minimun_number_bit_flips(10,7);

    // power_set({1,2,3});

    // cout<<single_number({4,1,2,1,2});

    cout<<single_number_II({5,5,5,6,4,4,4});

    return 0;
}