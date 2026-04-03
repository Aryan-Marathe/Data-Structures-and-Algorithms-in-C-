#include<bits/stdc++.h>
using namespace std;


int find_max(int arr[],int n){

    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }

    return max;
}


int find_sec_largest(vector<int> &vec,int n){

    int Largest=vec[0];
    int sLargest=-1;

    for(int i=0;i<n;i++){
        if(vec[i]>Largest){
            sLargest=Largest;
            Largest=vec[i];
        }
        else if(vec[i]<Largest && vec[i]>sLargest){
            sLargest =vec[i];
        }
    }

    return sLargest;
}


int find_sec_smallest(vector<int> &vec, int n){

    int smallest=vec[0];
    int sSmallest=INT_MAX;

    for(int i=0;i<n;i++){
        if(vec[i]<smallest){
            sSmallest=smallest;
            smallest=vec[i];
        }
        else if(vec[i]!=smallest && vec[i]<sSmallest){
            sSmallest =vec[i];
        }
    }

    return sSmallest;


}

bool check_sorted(vector<int> &vec,int n){

    for(int i=0;i<n;i++){
        if(vec[i]<=vec[i+1]){
            return true;
        }
        else{
            return false;
        }
    }
}


int remove_duplicates(vector<int> &vec, int n){

    int i=0;

        for(int j=1;j<n;j++){

            if(vec[i]!=vec[j]){
                vec[i+1]=vec[j];
                i+1;
            }
        }

    return (i+1);
    }

    
int left_rotate_by_one(vector<int> &vec , int n){

    int temp=vec[0];
    for(int i=0;i<n-1;i++){
        vec[i]=vec[i+1];
        if(vec[i]==vec[n-1]){
            vec[i]=temp;
        }
    }

    for(auto it: vec){
        cout<<it<<" ";
    }
}


void reverse(vector<int> &vec,int start ,int end){

    while (start<=end)
    {
        int temp=vec[start];
        vec[start]=vec[end];
        vec[end]=temp;
        start++;
        end--;   
    }
    
}
int left_roatate_by_k(vector<int> &vec,int n,int k){

    reverse(vec,0,k);
    reverse(vec,k,n);
    reverse(vec,0,n);   
}

int rortate_right_by_one(vector<int> &vec,int n){

    int temp=vec[n-1];

    for(int i=n-2;i>=0;i--){
        vec[i+1]=vec[i];
    }

    vec[0]=temp;

    for(auto it: vec){

        cout<<it<<" ";
    }
}


int move_zero_at_end(vector<int> &vec,int n){

    // vector<int> temp;

    // for(int i=0;i<n;i++){
    //     if(vec[i]!=0){
    //         temp.push_back(vec[i]);
    //     }

    // }

    // while (n-temp.size())
    // {
    //     temp.push_back(0);
    // }


    // for(auto it : temp){

    //     cout<<it<<" ";
    // }

    //OPTIMAL SOLUTION 


    int j=-1;
    for(int i=0;i<n;i++){

        if(vec[i]==0){

            j=i;
            break;
        }
    }

    for(int i=j+1;i<n;i++){

        if(vec[i]!=0){

            int temp=vec[i];
            vec[i]=vec[j];
            vec[j]=temp;
            j++;
        }
    }

    for(auto it : vec){

        cout<<it<<" ";
    }
    

}
vector<int> union_arrays(vector<int> &vec,vector<int> &vec1,int n,int m){

    // set<int> st;

    // for(int i=0;i<n;i++){
    //     st.insert(vec[i]);
    // }
    // for(int i=0;i<m;i++){
    //     st.insert(vec1[i]);
    // }

    // for( auto it : st){

    //     cout<<it<<" ";
    // }

    int i=0;
    int j=0;

    vector<int> union_array;

    while (i<n && j<m)
    {
        if(vec[i]<vec1[j])
        {
            if(union_array.size()==0 || union_array.back()!=vec[i]){
                union_array.push_back(vec[i]);
            }
            i++;
        }

        else{

            if(union_array.size()==0 || union_array.back()!=vec[j]){
                union_array.push_back(vec[j]);
            }
            j++;

        }
    }

    while (j<m)
    {

        if(union_array.size()==0 || union_array.back()!=vec[j]){
                union_array.push_back(vec[j]);
            }
            j++;
        
    }

    while (i<n)
    {

        if(union_array.size()==0 || union_array.back()!=vec[i]){
                union_array.push_back(vec[i]);
            }
            i++;
        
    }
    
    for(auto it : union_array){

        cout<<it<<" ";
    }
    
}

int inetrsection_arrays(vector<int> &vec,vector<int> &vec1, int n, int m){

    vector<int> intersect_array;

    int i=0;
    int j=0;

    while (i<n && j<m)
    {
        if(vec[i]<vec1[j]){
            i++;
        }

        else if(vec1[j]<vec[i])
        {
            j++;
        }

        else{

            intersect_array.push_back(vec[i]);
            i++;
            j++;
        }
        
    }

    for(auto it : intersect_array){

        cout<<it<<" ";
    }
    
    
    
}

int find_missing_num(vector<int> &vec,int n){

    // int hash_arr[num+1]={0};

    // for(int i=0;i<vec.size();i++){
    //     hash_arr[vec[i]]++;
    // }

    // for(int i=1;i<=num;i++){

    //     if(hash_arr[i]==0){

    //         return i;
    //     }
    // }

    //  OPTIMAL SOLUTION 

    int sum=n*(n+1)/2;

    int sum1=0;

    for(int i=0;i<vec.size();i++){

        sum=sum+vec[i];

    }

    return sum-sum1;


}


int max_consecutive_ones(vector<int> &vec,int n){

    int max=0;
    int cnt=0;

    for(int i=0;i<n;i++){

        if(vec[i]==1){
            cnt++;
        }
        else{
            if(cnt>max){
                max=cnt;
                cnt=0;
            }
        }
    }

    return max;
}


int find_num_appers_ones(vector<int> &vec,int n){

    // int hash_arr[n]={0};

    // for(int i=0;i<n;i++){

    //     hash_arr[vec[i]]++;
    // }

    // for(int i=1;i<n;i++){
    //     if(hash_arr[i]==1){
    //         return i;
    //     }
    // }

    //OPTIMAL SOLUTION 

    map<int,int> mpp;

    for(int i=0;i<n;i++){

        mpp[vec[i]]++;
    }

    for(auto it : mpp){
        if(it.second==1){
            return it.first;
        }
    }

}

int longest_sum_k(vector<int> &vec,int n,int k){

    int left=0;
    int right=0;
    long long sum=vec[0];
    int max_len=0;

    while (right<n)
    {
        while (left<=right && sum>k)
        {
            sum-=vec[left];
            left++;
        }

        if(sum==k){
            max_len=max(max_len,right-left);
        }

        right++;
        if(right<n){
            sum+=vec[right];
        }
        
    }

    return max_len;
    
}

int two_sum(vector<int> &vec,int n,int target){

    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(vec[i]+vec[j]==target){
    //             cout<<i<<" "<<j;
    //         }
    //     }
    // }

    // return false;

    int left=0;
    int right=n-1;

    sort(vec.begin(),vec.end());

    while (left<right)
    {
        int sum=vec[left]+vec[right];
        if(sum==target){
            return true;
        }

        else if(sum>target){
            right--;
        }

        else{
            left++;
        }
    }

    return false;
    
}


int sort_0_1_2_array(vector<int> &vec,int n){

    int low=0;
    int mid=0;
    int high=n-1;

    while (mid<=high)
    {
        if(vec[mid]==0){

            int temp=vec[mid];
            vec[mid]=vec[low];
            vec[low]=temp;
            mid++;
            low++;
        }

        else if(vec[mid]==1){
            mid++;
        }

        else{

            int temp=vec[mid];
            vec[mid]=vec[high];
            vec[high]=temp;
            high--;
        }

        
    }

    for(auto it: vec){

        cout<<it<<" ";
    }
    
}


int majority_ele(vector<int> &vec,int n){

    // map<int ,int> mpp;
    // int cnt=n/2;

    // for(int i=0;i<n;i++){

    //     mpp[vec[i]]++;
    // }

    // for(auto it : mpp){
    //     if(it.second>cnt){
    //         return it.first;
    //     }
    //     else{
    //     return -1;
    //     }
    // }

    //OPTIMAL SOLUTION {MOORE'S VOTING ALGORITHM}

    int cnt=0;
    int ele;

    for(int i=0;i<n;i++){

        if(cnt==0){
            ele=vec[i];
            cnt=1;
        }

        else if(vec[i]==ele){
            cnt++;
        }

        else{
            cnt--;
        }
    }

    int cnt1=0;

    for(int i=0;i<n;i++){
        if(vec[i]==ele){
            cnt1++;
        }
    }

    if(cnt1>n/2){
        return ele;
    }

    return -1;
    
}

int find_max_sum_subArray(vector<int> &vec,int n){

    // KADAN'S ALGORITHM

    int sum=0;
    int max=INT_MIN;
    int start;
    int ans_start=-1;
    int ans_end=-1;

    for(int i=0;i<n;i++){

        if(sum==0){
            start=i;
        }

        sum+=vec[i];

        if(sum>max){
            max=sum;
            ans_start=start;
            ans_end=i;
        }

        if(sum<0){
            sum=0;
        }
    }

    return max;


}


int rearrnage_array_ele(vector<int> &vec,int n){

    // vector<int> pos_num;
    // vector<int> neg_num;

    // for(int i=0;i<n;i++){
    //     if(vec[i]>0){
    //         pos_num.push_back(vec[i]);
           
    //     }

    //     else{
    //         neg_num.push_back(vec[i]);
    //     }
    // }

    // for(int i=0;i<n;i++){
    //     vec[2*i]=pos_num[i];
    //     vec[2*i+1]=neg_num[i];
    // }

    // for(auto it :vec){

    //     cout<<it<<" ";
    // }

    // OPTIMAL SOLUTION

    // { for equal number of positives and negatives in array}

    vector<int> ans_arr(n,0);
    int pos_idx=0;
    int neg_idx=1;

    for(int i=0;i<n;i++){

        if(vec[i]>0){
            ans_arr[pos_idx]=vec[i];
            pos_idx+=2;
        }

        else{
            ans_arr[neg_idx]=vec[i];
            neg_idx+=2;
        }
      
    }

    for(auto it : ans_arr){

        cout<<it<<" ";
    }


}

int find_next_permutation(vector<int> &vec,int n){

    int idx=-1;

    for(int i=n-2;i<=0;i--){
        if(vec[i]<vec[i+1]){
            idx=i;
            break;
        }
    }

    if(idx=-1){
        reverse(vec.begin(),vec.end());
    }

    for(int i=n-1;i<idx;i--){
        if(vec[i]>vec[idx]){
            swap(vec[i],vec[idx]);
            break;

        }
    }

    reverse(vec.begin()+idx+1,vec.end());

    for(auto it : vec){
        cout<<it<<" ";
    }
}

int find_leaders(vector<int> &vec,int n){

    int max_num=INT_MIN;
    vector<int> ans_arr;

    for(int i=n-1;i>0;i--){

        if(vec[i]>max_num){
            ans_arr.push_back(vec[i]);
            max_num=vec[i];
        }
    }

    for(auto it :ans_arr){
        cout<<it<<" ";
    }
}


int removeElements(vector<int> vec,int val){

    int n=vec.size();
    int i=0;
    int last=n-1;
    int cnt=0;

    while (i<=last)
    {
        if(vec[last]==val){
            last--;
        }
        else{

                if(vec[i]==val){
                    swap(vec[i],vec[last]);
                    last--;
                }
            }
            cnt++;
            
        }

        return cnt;
    }
    

int removeDuplicates(vector<int>& nums) {

    int n=nums.size();
    int prev=1;
    int nxt=2;
    int cnt=0;

    while (n)
    {
        if(nums[prev]==nums[nxt]){
            nxt++;
        }

        else{
            swap(nums[prev],nums[nxt]);
            prev++;
            cnt++;
        }
    }

    
    
    
}

int check_duplicates(vector<int> vec){
    int n=vec.size();
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[vec[i]]++;
    }

    for(auto it : mpp){
        if(it.second>=2){
            return false;
        }
        
    }
return true;
}





int main(){

    // int n;
    // cout<<"enter the size of the array : ";
    // cin>>n;

    // int arr[n];

    // for(int i=0;i<n;i++){

    //     cout<<"enter the "<<i<<"th element of the array : ";
    //     cin>>arr[i];
    
    // }






    int n;
    cout<<"enter the number of elements in the array : ";
    cin>>n;

    vector<int> vec;

    for(int i=0;i<n;i++){
        int ele;
        cout<<"enter the "<<i<<"th element in the array : ";
        cin>>ele;
        vec.push_back(ele);
    }

    // int m;
    // cout<<"enter the number of elements in the array : ";
    // cin>>m;

    // vector<int> vec1;

    // for(int i=0;i<m;i++){
    //     int ele;
    //     cout<<"enter the "<<i<<"th element in the array : ";
    //     cin>>ele;
    //     vec1.push_back(ele);
    // }




    // cout<<find_max(arr,n);

    // cout<<find_sec_largest(vec,n);

    // cout<<find_sec_smallest(vec,n);

    // cout<<check_sorted(vec,n);

    // remove_duplicates(vec,n);

    // left_rotate_by_one(vec,n);

    // left_roatate_by_k(vec,n,3);

    // rortate_right_by_one(vec,n);

    // move_zero_at_end(vec,n);

    // union_arrays(vec,vec1,n,m);

    // inetrsection_arrays(vec,vec1,n,m);

    // cout<<find_missing_num(vec,5);

    // cout<<max_consecutive_ones(vec,n);

    // cout<<find_num_appers_ones(vec,n);

    // cout<<longest_sum_k(vec,n,6);

    // two_sum(vec,n,9);

    // sort_0_1_2_array(vec,n);

    // cout<<majority_ele(vec,n);

    // cout<<find_max_sum_subArray(vec,n);

    // rearrnage_array_ele(vec,n);

    // find_next_permutation(vec,n);

    // find_leaders(vec,n);

    // cout<<removeElements(vec,2);

    // removeDuplicates(vec);

    // cout<<check_duplicates(vec);

    


    



    return 0;
}