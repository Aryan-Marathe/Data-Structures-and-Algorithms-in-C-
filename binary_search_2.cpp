#include<bits/stdc++.h>
using namespace std;


int total_hours(vector<int> &arr,int mid){
    int total_hr=0;

    for(int i=0;i<arr.size();i++){
        total_hr+=ceil((double)arr[i]/(double )mid);
    }
    return total_hr;
}

// int koko_eating_bananas(vector<int> &arr,int h){

//     //RETURN THE MIN. INTERGER 'K' SUCH THAT KOKO CAN EAT ALL BANANS WITHIN 'H' HOURS
//     sort(arr.begin(),arr.end());
//     int n=arr.size();
//     int low=0;
//     int high=find_max(arr);
//     int ans=INT_MAX;

//     while (low<=high)
//     {
//         int mid=low+high/2;
//         int total_hr=total_hours(arr,mid);
//         if(total_hr<=h){
//             ans=total_hr;
//             high=mid-1;
//         }
//         else{
//             low=mid+1;
//         }

//     }
//     return ans;
    
// }

//-----------------------------------------------------------------------------------------------

bool possible(vector<int> &arr,int day,int m,int k){
    int cnt=0;
    int num_buquets=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=day){
            cnt++;
        }
        else{
            num_buquets+=(cnt/k);
            cnt=0;
        }
        num_buquets+=(cnt/k);
        return num_buquets>=m;
    }
}
int min_days_to_make_M_buquets(vector<int> &arr,int m,int k){

    //FIND MIN. NUMBER OF DAYS TO MAKE M BUQUETS WITH ADJECENT K FLOWERS    

    // m-->number of buquets
    //k-->adjecente flowers


    long long val=m*1LL*k*1LL;
    if(val>arr.size()){
        return -1;
    }
    int mini=INT_MAX;
    int maxi=INT_MIN;

    for(int i=0;i<arr.size();i++){
        mini=min(mini,arr[i]);
        maxi=max(maxi,arr[i]);
    }

    int low=mini;
    int high=maxi;

    while (low<=high)
    {
       int mid=(low+high)/2;
       if(possible(arr,mid,m,k)){
        high=mid-1;
       }
       else{
        low=mid+1;
       }
    }
    return low;
}

//-----------------------------------------------------------------------------------------------
int find_min(vector<int> &arr){
    int mini=INT_MAX;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<mini){
            mini=arr[i];
        }
    }
    return mini;
}

int find_max(vector<int> &arr){
    int maxi=INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>maxi){
            maxi=arr[i];
        }
    }
    return maxi;
}


//-------------------------------------------------------------------------------------------------
int find_sum(vector<int> &arr,int mid){
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=ceil((double)arr[i]/(double)mid);
    }

    return sum;
}
int find_smallest_divisor(vector<int> &arr,int threshold){

    // FIND THE DIVISOR UPON SUM GIVES THE VALUE LESS THAN OR EQUAL TO THRESHOLD

    int ans=0;
    int low=find_min(arr);
    int high=find_max(arr);
    while (low<=high)
    {
        int mid=(low+high)/2;
        if(find_sum(arr,mid)<=threshold){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;   
}


//------------------------------------------------------------------------------------------------------
int find_sum_array(vector<int> &arr){
    int sum=0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum+=arr[i];
    }
    return sum;
}

int find_days(vector<int> &arr,int mid){

    int days=1;
    int load=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]+load<=mid){
            days+=1;
            load=arr[i];
        }
        else{
            load+=arr[i];
        }
    }
    return days;
}
int find_min_capacity_ship(vector<int> &arr,int days){

    //FIND LEAST CAPACITY OF THE SHIP SUCH THAT IT CAN CARRY ALL THE LOAD WITHIN GIVEN DAYS 

    int low=find_max(arr);
    int high=find_sum_array(arr);

    while (low<=high)
    {
        int mid=(low+high)/2;
        int num_days=find_days(arr,mid);
        if(num_days<=days){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
    
}

//----------------------------------------------------------------------------------------------


int find_k_th_missing_num(vector<int> &arr,int k){
    int low=0;
    int high=arr.size()-1;
    while (low<=high)
    {
        int mid=(low+high)/2;
        int missing=arr[mid]-(mid+1);
        if(missing<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        return k+high+1;
    }
    
}

//------------------------------------------------------------------------------------------------

bool PlaceCows(vector<int> &arr,int mid,int cows){
    int cntCows=1;
    int last=arr[0];
    for(int i=0;i<arr.size();i++){
        if(arr[i]-last>=mid){
            cntCows++;
            last=arr[i];
        }
    }

    if(cntCows>=cows){
        return true;
    }
    else{
        return false;
    }
}
int aggrasive_cows(vector<int> &arr,int cows){

    //RETURN THE MINIMUN DISTANCE BETWEEN THE COWS ARE MAXIMUM
    sort(arr.begin(),arr.end());
    int low=1;
    int high=find_max(arr);
    int ans=-1;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if(PlaceCows(arr,mid,cows)==true){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}

//--------------------------------------------------------------------------------------
int countStudents(vector<int> &arr,int pages){
    int students=1;
    long long pagesStudent=0;
    for(int i=0;i<arr.size();i++){
        if(pagesStudent+arr[i]<=pages){
            pagesStudent+=arr[i];
        }
        else{
            students+=1;
            pagesStudent=arr[i];
        }
    }
    return students;
}
int allocate_books(vector<int> &arr,int students){

    if(students>arr.size()) return -1;
    int low=find_max(arr);
    int high=find_sum(arr);

    while (low<=high)
    {
        int mid=(low+high)/2;
        int student=countStudents(arr,mid);
        if(student>students){
            low=mid+1
        }
        else{
            high=mid-1;
        }
    }
    return low;
    
}
int main(){


    int n;
    cout<<"enter the size of array : ";
    cin>>n;

    vector<int> arr;
    for(int i=0;i<n;i++){
        int ele;
        cout<<"enter the "<<i<<"th element : ";
        cin>>ele;
        arr.push_back(ele);
    }

    // cout<<koko_eating_bananas(arr,7);

    // cout<<min_days_to_make_M_buquets(arr,2,3);

    // cout<<find_smallest_divisor(arr,6);

    // cout<<find_min_capacity_ship(arr,5);

    // cout<<find_k_th_missing_num(arr,4);

    // cout<<aggrasive_cows(arr,4);

    // cout<<allocate_books(arr,4);
    
    return 0;
}