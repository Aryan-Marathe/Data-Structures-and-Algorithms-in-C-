#include<bits/stdc++.h>
using namespace std;


// int hash_func(int querry_ele,int arr,n){

//     map<int,int> mpp;
//     for(int i=0;i<n;i++){
//         mpp[arr[i]]++;
//     }
//     return mpp[querry_ele];
// }





int main(){


    int n;
    cout<<"enter the size of the array : ";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cout<<"enter the "<<i<<"ith element in thge array";
        cin>>arr[i];
    }

    int querry_num;
    cout<<"enter the number of queries : ";
    cin>>querry_num;

    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    

    while (querry_num--)
    {
        int querry_ele;
        cout<<"enter the querry element :";
        cin>>querry_ele;
    }

    int max=0;
    for(auto it:mpp){

        cout<<it.first<<"->"<<it.second<<endl;
        if(it.second>max){
            max=it.second;
        }

    }

    cout<<"maximum frequency is : "<<max;
    



    // int n;
    // cout<<"enter the size of array :";
    // cin>>n;

    // int arr[n];

    // int querry_num;
    // cout<<"enter the number of elements : ";
    // cin>>querry_num;

    // while(querry_num--){
    //     int querry_ele;
    //     cout<<"enter the querry : ";
    //     cin>>querry_ele;
    //     cout<<hash_func(querry_ele,arr,n);
    // }

    

    
    

    /*
    //CHARACTER HASHING 


    string s;
    cout<<"enter the string :";
    cin>>s;

    //HASHING   
    int hash_arr[256]={0};
    for(int i=0;i<s.size();i++){
        hash_arr[s[i]]++;
    }

    int querry_num;
    cout<<"enter the number of queries: ";
    cin>>querry_num;

    while (querry_num--)
    {
        char querry_ele;
        cin>>querry_ele;
        //FETCHING
        cout<<hash_arr[querry_ele]<<endl;
    }
    */





    /*
    //NUMBER HASHING 
    
    
    int n;
    cout<<"enter the size of the array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"enter the "<<i<<"th element in the array: ";
        cin>>arr[i];
    }

    for(auto i:arr){
        cout<<i<<" ";
    }

    //HASHING 
    int hash_arr[13]={0};
    for(int i=0;i<n;i++){
        hash_arr[arr[i]]=+1;
    }

    int querry_num;
    cout<<"enter the number of querry elements : ";
    cin>>querry_num;

   
    for(int i=0;i<querry_num;i++){
        int element;
        cin>>element;

        //FECTHING OF ELEMENT
        cout<<hash_arr[element]<<endl;
    }
    
    */

    return 0;
}