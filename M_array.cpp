#include<bits/stdc++.h>
using namespace std;


int longest_sequence(vector<int> &vec){

    int n=vec.size();

    // if(n==0){
    //     return 0;
    // }

    // sort(vec.begin(),vec.end());

    // int lastSmaller=INT_MIN;

    // int cnt=0;
    // int longest=1;

    // for(int i=0;i<n;i++){
    //     if(vec[i]-1==lastSmaller){
    //         cnt++;
    //         lastSmaller=vec[i];
    //     }
    //     else if(lastSmaller!=vec[i]){
    //         cnt=1;
    //         lastSmaller=vec[i];
    //     }

    //     longest=max(longest,cnt);
    // }

    // return longest;

    //OPTIMAL SOLUTION

    if(n==0){
        return 0;
    }

    int longest=1;
    unordered_set<int> st;

    for(int i=0;i<n;i++){
        st.insert(vec[i]);
    }

    for(auto it : st){

        if(st.find(it-1)==st.end()){
            int cnt=1;
            int x=it;

            while (st.find(x+1)!=st.end())
            {
               x=x+1;
               cnt=cnt+1;
            }

            longest=max(longest,cnt);
            
        }
    }

    return longest;

}



//M-ARRAY 


int mark_rows(vector<vector<int>> &arr,int i,int m){

    for(int j=0;j<m;j++){
        if(arr[i][j]!=0){
            arr[i][j]=-1;
        }
    }
}

int mark_columns(vector<vector<int>> &arr,int j,int n){

    for(int i=0;i<n;i++){
        if(arr[i][j]!=0){
            arr[i][j]=-1;
        }
    }
}

int set_matrix_zeros(vector<vector<int>> &arr,int n,int m){

    //BRUTE FORCE SOLUTION 

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(arr[i][j]==0){
    //             mark_rows(arr,i,m);
    //             mark_columns(arr,j,n);
    //         }
    //     }
    // }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(arr[i][j]==-1){
    //             arr[i][j]=0;
    //         }
    //     }
    // }

    //BETTER SOLUTION 

    // int col[m]={0};
    // int row[n]={0};

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(arr[i][j]==0){
    //             col[j]=1;
    //             row[i]=1;
    //         }
    //     }
    // }


    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(col[j]==1 || row[i]==1){
    //             arr[i][j]=0;
    //         }
    //     }
    // }


    //OPTIMAL SOLUTION 

    int col0=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==0){
                //mark i-th row
                arr[i][0]=0;
                //mark j-th column
                if(j!=0){
                    arr[j][0]=0;
                }
                else{
                    col0=0;
                }
                
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]!=0){
                //check column and row
                if(arr[0][j]==0 || arr[i][0]==0){
                    arr[i][j]=0;
                }
            }
        }
    }

    if(arr[0][0]==0){
        for(int j=0;j<m;j++){
            arr[0][j]=0;
        }
    }

    if(col0==0){
        for(int i=0;i<n;i++){
            arr[i][0]=0;
        }
    }

    cout<<"modified array :"<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"\t"<<arr[i][j];
        }
        cout<<endl;
    }


}


int rortate_matrix_by_90(vector<vector<int>> &arr,int n,int m){

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<m;j++){
            if(i!=j){
                swap(arr[i][j],arr[j][i]);
            }
        }
    }
    
    for(int i=0;i<n;i++){

        reverse(arr[i].begin(),arr[i].end()); 
        
    }

    

    cout<<"modified array :"<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"\t"<<arr[i][j];
        }
        cout<<endl;
    }

}

int print_mat_spiral_form(vector<vector<int>> &arr){

    int n=arr.size();
    int m=arr[0].size();
    int top=0;
    int bottom=n-1;
    int left=0;
    int right=m-1;
    vector<int> ans;

    while (left<=right && top<=bottom)
    {
       //right moment 

       for(int i=left;i<=right;i++){
        ans.push_back(arr[top][i]);
       }
       top++;

       for(int i=top;i<=right;i++){
        ans.push_back(arr[i][right]);
       }
       right--;

       if(top<=bottom){
       for(int i=right;i>=bottom;i--){
        ans.push_back(arr[bottom][i]);
       
       }
    
       bottom--;
    } 

       if(left<=right){
       for(int i=bottom;i>=top;i--){
        ans.push_back(arr[i][left]);
       }
       left++;
    }
       

    }

    for(auto it : ans){
        cout<<it<<" ";
    }
    
}

int combination_nCr(int column,int row){
    // Use formula for combination nCr = n!/r!*(n-r)!

    int result=1;

    for(int i=0;i<row;i++){

        result=result*(column-i);
        result=result/(i+1);
    }

    return result;
}

int ele_in_pascals_triangle(){

    //Search about pascals triangle 

    cout<<combination_nCr(8,4);

    
}

vector<int> print_row_in_pascal_triangle(int column){

    //pascals triangle 

            //                     1
            //                 1       1
            //             1       2       1
            //         1       3       3       1
            //     1       4       6       4       1
            // 1       5       10      10      5       1

    
            // use the formula ans*(row-column)/column

    long long ans=1;
    vector<int> ansRow;
    ansRow.push_back(1);

    for(int i=1;i<column;i++){
        ans=ans*(column-i);
        ans=ans/i;
        ansRow.push_back(ans);    
    }

    return ansRow;
     
}

vector<vector<int>> print_pascals_triangle(int column){

    vector<vector<int>> ansTriangle;
    for(int i=0;i<=column;i++){
        ansTriangle.push_back(print_row_in_pascal_triangle(i));
    }

    return ansTriangle;

}


int majority_ele_n_3(vector<int> &vec,int n){

    vector<int> ans;
    // map<int,int> mpp;
    int min = n/3+1;

    // for(int i=0;i<n;i++){

    //     mpp[vec[i]]++;
    //     if(mpp[vec[i]]==min){
    //         ans.push_back(vec[i]);
    //     }

    // }

    // for(auto it : ans){
    //     cout<<it<<" ";
    // }

    int cnt1=0;
    int ele1=-1;
    int cnt2 =0;
    int ele2=-1;

    for(int i=0;i<n;i++){
        if(cnt1==0 && vec[i]!=ele2){
            cnt1=1;
            ele1=vec[i];
        }
        else if(cnt2 ==0 && vec[i]!=ele1){
            cnt2=1;
            ele2=vec[i];
        }
        else if(vec[i]==ele1){
            cnt1++;
        }
        else if(vec[i]==ele2){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    // vector<int> ans;

    cnt1=0;
    cnt2=0;

    for(int i=0;i<n;i++){
        if(ele1==vec[i]){
            cnt1++;
        }
        if(ele2==vec[i]){
            cnt2++;
        }
    }

    if(cnt1>=min){
        ans.push_back(ele1);
    }
    if(cnt2>=min){
        ans.push_back(ele2);
    }

    for(auto it : ans){
        cout<<it<<" ";
    }
}


int three_sum(vector<int> vec){
        
    // Return all the unique triplets which add to zero 

    int n=vec.size();
    // set<int> st;

    //BRUTE FORCE

    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         for(int k=j+1;k<n;k++){
    //             if(vec[i]+vec[j]+vec[k]==0){
    //                 vector<int> temp={vec[i],vec[j],vec[k]};
    //                 sort(temp.begin(),temp.end());
    //                 st.insert(temp.begin(),temp.end());   
    //             }
    //         }
    //     }
    // }

    //BETTER SOLUTION 

    // for(int i=0;i<n;i++){
    //     set<int> hashset;
    //     for(int j=i+1;j<n;j++){
    //         int third=-(vec[i]+vec[j]);
    //         if(hashset.find(third)!=hashset.end()){
    //             vector<int> temp={vec[i],vec[j],third};
    //             sort(temp.begin(),temp.end());
    //             st.insert(vec[i]);
    //         }
    //     }
    // }

    vector<vector<int>> ans;

    sort(vec.begin(),vec.end());

    for(int i=0;i<n;i++){
        if(i>0 && vec[i]==vec[i+1]){
            continue;
        }
        int j=i+1;
        int k=n-1;

        while (j<k)
        {
            int sum=vec[i]+vec[j]+vec[k];

            if(sum>0){
                k--;
            }
            else if(sum<0){
                j++;
            }
            else{
                vector<int> temp={vec[i],vec[j],vec[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j<k && vec[j]==vec[j-1]) 
                {
                    j++;
                }
                while (j<k && vec[k]==vec[k+1])
                {
                    k--;
                }
                
                
            }
        }
        
    }


}

int four_sum(vector<int> vec, int target){

    vector<vector<int>> ans;
    int n=vec.size();

    sort(vec.begin(),vec.end());

    for(int i=0;i<n;i++){
        if(i>0 && vec[i]==vec[i+1]) continue;

        for(int j=i+1;j<n;j++){
            if(j!=i+1 && vec[j]==vec[j-1]) continue;

            int k=j+1;
            int l=n-1;

            while (k<l)
            {
                long long sum=vec[i]+vec[j];
                sum+=vec[k];
                sum+=vec[l];

                if(sum==target){
                    vector<int> temp={vec[i],vec[j],vec[k],vec[l]};
                    ans.push_back(temp); 
                    k++;
                    l--;
                    while (k<l && vec[k]==vec[k-1])
                    {
                        k++;
                    }
                    while (k<l && vec[l]==vec[l+1])
                    {
                        l--;
                    }
                }
                else if(sum<target){
                    k++;
                }
                else{
                    l--;
                }
            }
            
        }
    }

    
}


int subArraywithXOR_K(vector<int> &vec,int k){
    int n=vec.size();
    int xr=0;
    map<int,int> mpp;
    mpp[xr]++; //{0,1}
    int cnt=0;
    for(int i=0;i<n;i++){
        xr=xr^vec[i];
        int x=xr^k;
        cnt+=mpp[x];
        mpp[xr]++;
    }
    return cnt;
}


int main(){

    vector<int> vec;

    int n;

    cout<<"enter the size of the array : ";
    cin>>n;

    for(int i=0;i<n;i++){
        int ele;
        cout<<"enter the "<<i<<"th element in the array :";
        cin>>ele;
        vec.push_back(ele);
    }

//    cout<<longest_sequence(vec);


// int n,m;

// cout<<"enter the number of rows : ";
// cin>>n;
// cout<<"enter the number of columns : ";
// cin>>m;
// vector<vector<int>> arr(n,vector<int>(m));

//     cout << "\n2D Array Input:\n";
//     for (int i = 0; i < n; i++) {
//         for (int j =0; j < m; j++) {
//             cin >> arr[i][j];
//         }
//     }

//     cout << "\nThe 2-D Array is:\n";
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cout << "\t" << arr[i][j];
//         }
//         cout << endl;
//     }

    // set_matrix_zeros(arr,n,m);

    // rortate_matrix_by_90(arr,n,m);

    // print_mat_spiral_form(arr);

    // ele_in_pascals_triangle();

    // cout<<print_row_in_pascal_triangle(6);

    // cout<<print_pascals_triangle(5);

    // majority_ele_n_3(vec,n);

    // three_sum(vec);

    cout<<subArraywithXOR_K(vec,6);



    return 0;
}

