#include<bits/stdc++.h>
using namespace std;

int binary_serach_iterative(vector<int> &arr, int target){

    int n=arr.size();
    int low=0;
    int high=n-1;
    while (low<=high)
    {
        int mid=low+high/2;

        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return -1;
    
}

int binary_search_recurssive(vector<int> &arr, int low,int high,int target){
    int n=arr.size();
    low=0;
    high=n-1;

    if(low<high){
        return -1;
    }

    int mid=(low+high)/2;

    if(arr[mid]==target){
        return mid;
    }
    else if(target>arr[mid]){
        return binary_search_recurssive(arr,mid+1,high,target);
    }
    else{
        return binary_search_recurssive(arr,low,mid-1,target);
    }
}

int find_lower_bound(vector<int> &arr,int target){

    //Lower Bound --> smallest index such that arr[index]>=n

    int n=arr.size();
    int low=0;
    int high=n-1;
    int ans=n;

    while (low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return ans;

    //There is a direct way to find lower bound

    // int lower_bound=__lower_bound(arr.begin(),arr.end(),target);  //the fucntion will return the iterator of lower bound
    // int idx=lower_bound-arr.begin(); //lower bound index
    // cout<<idx;

}


int find_upper_bound(vector<int> &arr,int target){

    //Upper Bound --> smallest index such that arr[index]>n

    int n=arr.size();
    int low=0;
    int high=n-1;
    int ans=n;

    while (low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>target){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;

    //There is a direct way to find upper bound

    // int upper_bound=__upper_bound(arr.begin(),arr.end(),target);  //the fucntion will return the iterator of upper bound
    // int idx=upper_bound-arr.begin(); //upper bound index
    // cout<<idx;


}

int ceil_value(vector<int> &arr,int target){

    int n=arr.size();
    int low=0;
    int high=n-1;
    int ceil_val=n;

    while (low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>=target){
            ceil_val=arr[mid];
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return ceil_val;
}


int floor_value(vector<int> &arr,int target){

    int n=arr.size();
    int low=0;
    int high=n-1;
    int floor_val=n;

    while (low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]<=target){
            floor_val=arr[mid];
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

    return floor_val;
}




vector<int> first_last_occurance_by_low_up_bound(vector<int> &arr,int target){
    int n=arr.size();
    
    //ONE SOLUTION BY USING LOWER AND UPPER BOUND 

    int lower_bound=find_lower_bound(arr,8);
    if(lower_bound==n || arr[lower_bound] != target){
        return {-1,-1};
    }
    else{
        return {lower_bound,find_upper_bound(arr,8)-1};
    }
}


int find_first(vector<int> &arr,int target){
    int n=arr.size();
    int idx1=-1;
    int low=0;
    int high=n-1;

    while (low<high)
    {
        int mid=low+high/2;
        if(arr[mid]==target){
            idx1=mid;
        }
        else{
            high=mid-1;
        }
    }
    return idx1;
    
}

int find_last(vector<int> &arr,int target){
    int n=arr.size();
    int last_idx=-1;
    int low=0;
    int high=n-1;

    while (low<high)
    {

        int mid=low+high/2;
        if(arr[mid]==target){
            last_idx=mid;
        }
        else{
            low=mid+1;
        }
    }
    return last_idx;
    
}
int find_first_last(vector<int> &arr,int target){

    vector<int> ans;
    ans.push_back(find_first(arr,8));
    ans.push_back(find_last(arr,8));

    for(auto it : ans){
        cout<<it<<" ";
    }
}


int search_in_rotated_array(vector<int> &arr, int target){

    //for unique elements 

    int n=arr.size();
    int low=0;
    int high=n-1;
    while (low<=high)
    {
        int mid=low+high/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<=target && target<=arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(arr[mid]<=target && target<=arr[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return -1; 
    
}

string encode(vector<string>& strs) {

        vector<int> size;
        for(auto it : strs){
            int str_size=it.size();
            size.push_back(str_size);
        }

        string dummy_str;
        for(int i=0;i<size.size();i++){
             dummy_str=size[i]+"#"+strs[i];
        }

        return dummy_str;

    }


int search_in_rotated_array_II(vector<int> &arr, int target){

    //FOR DUPLICATE ELEMENTS    

    int n=arr.size();
    int low=0;
    int high=n-1;
    while (low<=high)
    {
        int mid=low+high/2;
        if(arr[mid]==target){
            return mid;
        }

        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low++;
            high--;
            continue;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<=target && target<=arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(arr[mid]<=target && target<=arr[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return -1; 

}

int find_min_roatated_array(vector<int> & arr){

    //FOR UNIQUE ELEMENTS

    int n=arr.size();
    int ans=INT_MAX;
    int low=0;
    int high=n-1;

    while (low<=high)
    {
        int mid=low+high/2;

        if(arr[low]<=arr[high]){
            ans=min(ans,arr[low]);
            break;
        }

        if(arr[low]<=arr[mid]){

            ans=min(ans,arr[low]);
            low=mid+1;
        }

        else{
           high=mid-1;
           ans=min(ans,arr[mid]);
        }
    }

    return ans;
    
}


int number_times_array_roatated(vector<int> &arr){
    int n=arr.size();
    int ans=INT_MAX;
    int low=0;
    int high=n-1;
    int idx=-1;

    while (low<=high)
    {
        int mid=low+high/2;

         if(arr[low]<=arr[high]){
            if(arr[low]<ans){
                idx=low;
                ans=arr[low];
            }
            break;
        }
        if(arr[low]<=arr[mid]){

            if(arr[low]<ans){
                idx=low;
                ans=arr[low];
            }
            low=mid+1;
        }

        else{
           high=mid-1;
           if(arr[mid]<ans){
                idx=mid;
                ans=arr[mid];
            }
        }
    }

    return idx;
}


int find_single_ele(vector<int> &arr){

    //check for similar element
    // { even idx, odd idx } --> the element is on right half and eliminate the left half
    // { odd idx, even idx } --> the element is on left half and eliminate the right half

    // element is single when arr[left]!=ele && arr[right]!=ele

    int n=arr.size();

    if(n==1) return arr[0];

    if(arr[0]!=arr[1]) return arr[0];
    if(arr[n-1]!=arr[n-2]) return arr[n-1];

    int low=1;
    int high=n-1;

    while(low<=high){
        int mid=low+high/2;

        if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1]){
            return arr[mid];
        }

        if((mid%2 ==1 && arr[mid]==arr[mid-1]) || (mid%2==0 && arr[mid]==arr[mid+1])){
            low=mid+1;
        }

        else{
            high=mid-1;
        }
    }

    return -1;
}

int find_peak_ele(vector<int> &arr){

    // defination --> arr[i-1]<arr[i] && arr[i+1]<arr[i]


    int n=arr.size();

    if(n==1) return 0;

    if(arr[0]>arr[1]) return 0;
    if(arr[n-1]>arr[n-2]) return n-1;

    int low=1;
    int high=n-2;

    while (low<=high)
    {
        int mid=low+high/2;

        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
            return mid;
        }

        else if(arr[mid]<arr[mid+1]){
            low=mid+1;
        }
        else if(arr[mid]<arr[mid-1]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

int find_sqrt(int ele){

    //LINEAR APPROCH

    // int ans=1;

    // for(int i=1;i<=ele;i++){
    //     if(i*i<=ele){
    //         ans=i;
    //     }
    //     else{
    //         break;
    //     }
    // }
    // return ans;


    int ans=1;
    int low=1;
    int high=ele;

    while (low<=high)
    {
        int mid=low+high/2;
        long long mul=mid*mid;
        if((mul)<=ele){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
    
}


int func(int mid,int n,int m){

    //return 1 if == m
    //return 0 if < m
    //return 2 if > m
    
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans=ans*mid;
        if(ans>m){
            return 2;
        }
        else if(ans==m){
            return 1;
        }
        return 0;
    }
}


int find_nth_root(int n,int m){
    int low=1;
    int high=m;

    while (low<=high)
    {
        int mid=low+high/2;
        int midN=func(mid,n,m);
        if(midN==1){
            return mid;
        }
        else if(midN==0)
        { low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
int main(){

    // int n;
    // cout<<"enter the size of the array : ";
    // cin>>n;

    // vector<int> arr;  
    // for (int i = 0; i < n; i++)
    // {
    //    int ele;
    //    cout<<"enter the "<<i<<"th element : ";
    //    cin>>ele;
    //    arr.push_back(ele);
    // }
    

    // cout<<binary_serach_iterative(arr,7);

    // cout<<binary_search_recurssive(arr,0,n-1,7);

    // cout<<find_lower_bound(arr,4);

    // cout<<ceil_value(arr,4);

    // cout<<floor_value(arr,8);

    // cout<<first_last_occurance_by_low_up_bound(arr,8);

    // find_first_last(arr,8);

    // search_in_rotated_array(arr,3);

    // vector<string> strs;
    // strs.push_back({"hello","world"});
    // cout<<encode(strs);

    // search_in_rotated_array_II(arr,6);

    // cout<<find_min_roatated_array(arr);

    // cout<<number_times_array_roatated(arr);

    // cout<<find_single_ele(arr);

    // find_peak_ele(arr);

    // cout<<find_sqrt(64);

    // cout<<find_nth_root(36);

    return 0;
}