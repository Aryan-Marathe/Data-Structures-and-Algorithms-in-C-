#include<bits/stdc++.h>
using namespace std;

bool valid_paranthisis(string s){
    stack<char> st;

    for(int i=0;i<s.size();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else{
            if(st.empty()){
                return true;
            }

            char ch=st.top();
            st.pop();

            if((s[i]==')' && ch=='(') || (s[i]==']' && ch=='[' )|| (s[i]=='}' && ch=='{')){
                return true;
            }
            else{
                return false;
            }
        }
    }

    return st.empty();
}

int check_prority(char ch){
    if(ch=='^'){
        return 3;
    }
    else if(ch=='*' || ch=='/'){
        return 2;
    }
    else if(ch=='+' || ch=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infix_to_postfix(string str){
    
    int i=0;
    string ans="";
    stack<char> st;

    while (i<str.size())
    {
        if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z') || (str[i]>='0' && str[i]<='9')){
            ans+=str[i];
        }
        else if(str[i]=='('){
            st.push(str[i]);
        }
        else if(str[i]==')'){
            while(!st.empty()&& st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while (!st.empty() && check_prority(str[i])<=check_prority(st.top()))
            {
                ans+=st.top();
                st.pop();
            }
            st.push(str[i]);
        } 
         i++;
    }
   while (!st.empty())
   {
    ans+=st.top();
    st.pop();
   }
   
   return ans;
}



string infix_to_prefix(string str){
    reverse(str.begin(),str.end());

    for(int i=0;i<str.size();i++){
        if(str[i]=='('){
            str[i]=')';
        }
        else if(str[i]==')'){
            str[i]='(';
        }
    }

    int i=0;
    string ans="";
    stack<char> st;

    while (i < str.size())
    {
        if(isalnum(str[i])){
            ans+=str[i];
        }
        else if(str[i]=='('){
            st.push(str[i]);
        }
        else if(str[i]==')'){
            while (!st.empty() && st.top()!='(')
            {
               ans+=st.top();
               st.pop();
            }
            if(!st.empty()) st.pop();    
        }
        else{
            if(str[i]=='^'){
                while (!st.empty() && check_prority(str[i])<=check_prority(st.top()))
                {
                    ans+=st.top();
                    st.pop();
                }   
            }
            else{
                while (!st.empty() && check_prority(str[i])<check_prority(st.top()))
                {
                    ans+=st.top();
                    st.pop();
                }   
            }

            st.push(str[i]);
        }
        i++;
    }

    while (!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    
    reverse(ans.begin(),ans.end());
    return ans;
}

string postfix_to_infix(string str){
    stack<string> st;
    int i=0;
    while (i<str.size())
    {
        if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z') || (str[i]>='0' && str[i]<='9')){
            st.push(string(1,str[i]));
        }
        else{
            
                string top1=st.top();
                st.pop();
                string top2=st.top();
                st.pop();

                string ans="("+top2+string(1,str[i])+top1+")";
                st.push(ans);  
        }
        i++;
    }
    return st.top();
}

string prefix_to_infix(string str){

    stack<string> st;
    int i=str.size()-1;
    while (i>=0)
    {
        if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z') || (str[i]>='0' && str[i]<='9')){
            st.push(string(1,str[i]));
        }
        else{
            
                string top1=st.top();
                st.pop();
                string top2=st.top();
                st.pop();

                string ans="("+top1+string(1,str[i])+top2+")";
                st.push(ans);  
        }
        i--;
    }
    return st.top();
}

string postfix_to_prefix(string str){
    stack<string> st;
    int i=0;
    while (i<str.size())
    {
        if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z') || (str[i]>='0' && str[i]<='9')){
            st.push(string(1,str[i]));
        }
        else{
            
                string top1=st.top();
                st.pop();
                string top2=st.top();
                st.pop();

                string ans=string(1,str[i])+top2+top1;
                st.push(ans);  
        }
        i++;
    }
    return st.top();
}

string prefix_to_postfix(string str){

    stack<string> st;
    int i=str.size()-1;
    while (i>=0)
    {
        if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z') || (str[i]>='0' && str[i]<='9')){
            st.push(string(1,str[i]));
        }
        else{
            
                string top1=st.top();
                st.pop();
                string top2=st.top();
                st.pop();

                string ans=top2+top1+string(1,str[i]);
                st.push(ans);  
        }
        i--;
    }
    return st.top();
}

int next_greater_element(vector<int> &arr){

    //find out the next greater element in the array for every element in array 

    
    stack<int> st;
    vector<int> ans;

    for(int i=arr.size()-1;i>=0;i--){
        while (!st.empty() && st.top()<=arr[i])
        {
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=st.top();
        }
        st.push(arr[i]);
        
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

int next_greater_element_2(vector<int> &arr){
    vector<int> ans;
    stack<int> st;

    for(int i=2*arr.size()-1;i>=0;i--){
        while (!st.empty() && st.top()<=arr[i%arr.size()])
        {
            st.pop();
        }
        if(i<arr.size()){
            ans[i]=st.empty()? -1:st.top();
        }
        st.push(arr[i%arr.size()]);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

int previous_smaller_element(vector<int> &arr){
    stack<int> st;
    vector<int> ans;

    for(int i=0;i<arr.size();i++){
        while (!st.empty() && st.top()>=arr[i])
        {
            st.pop();
        }
        ans[i]=st.empty()? -1:st.top();
        st.push(arr[i]);
        
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}


int prefix_max(vector<int> &arr){

    vector<int> prefix_max;
    
    prefix_max[0]=arr[0];
    for(int i=1;i<arr.size();i++){
        prefix_max[i]=max(prefix_max[i-1],arr[i]);
    }
}

int suffix_max(vector<int> &arr){

    vector<int> suffix_max;

    suffix_max[arr.size()-1]=arr[arr.size()-1];
    for(int i=arr.size()-1;i>0;i--){
        suffix_max[i]=max(suffix_max[i+1],arr[i]);
    }
}
int trapping_the_rain_water(vector<int> &arr){

    int leftMax=0;
    int rightMax=0;
    int total=0;
    int l=0;
    int r=arr.size()-1;

    while (l<r)
    {
        if(arr[l]< arr[r]){
            if(leftMax>rightMax){
                total+=leftMax;
                total-=arr[l];
            }
            else{
                leftMax=arr[l];

            }

            l++;

        }

        else{
            if(rightMax>leftMax){
                total+=rightMax;
                total-=arr[r];
            }
            else{
                rightMax=arr[r];
            }

            r--;
        }
    }
    
    return total;
}

int sum_subarray_minimum(vector<int> &arr){

    //find all the sub arrays of the given array and get their minimun 
    //return the sum of those minimum if sum is large the return the mod value with (1e9+7)

    


}
int main(){

    int n;
    cout<<"enter the size of array : ";
    cin>>n;

    vector<int> arr;

    for(int i=0;i<n;i++){
        int ele;
        cout<<"enter the "<<i<<"th element in array :";
        cin>>ele;
        arr.push_back(ele);
    }
    // cout<<valid_paranthisis("()()[{}]");

    // cout<<infix_to_postfix("(a+b)*(m-n)");
    
    // cout<<infix_to_prefix("(a+b)*c-d+f");

    // cout<<postfix_to_infix("ab-de+f*/");

    // cout<<prefix_to_infix("*+pq-mn");

    // cout<<postfix_to_prefix("ab-de+f*/");

    // cout<<prefix_to_postfix("/-ab*+def");

    // next_greater_element(arr);

    // next_greater_element_2(arr);

    // previous_smaller_element(arr);

    // cout<<trapping_the_rain_water(arr);



    
    return 0;
}