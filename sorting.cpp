#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int n){

    for(int i=0;i<=n-2;i++)
    {
        int min_index=i;
        for(int j=0;j<=n-1;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }

        int temp=arr[min_index];
        arr[min_index]=arr[i];
        arr[i]=temp;
    }

    for(int i=0;i<n;i++){

        cout<<arr[i]<<" ";
    }

    }

    void bubble_sort(int arr[],int n){
        for(int i=n-1;i<=1;i--){

            int didSwap=0;
            for(int j=0;j<i-1;j++){
                if(arr[j]>arr[j+1]){
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    didSwap=1;
                }
            }

            if(didSwap=0){
                break;
            }
        }

        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    }

    void insertion_sort(int arr[],int n){

        for(int i=0;i<=n-1;i++){
            int j=i;
            while (j>0 && arr[j-1]>arr[j])
            {
                int temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
                j--;
            }
            
        }

        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    }


    




int main(){

    int n;
    cout<<"enter the size of array";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){

        cout<<"enter the "<<i<<"th element of the array";
        cin>>arr[i];
    }

    // selection_sort(arr,n);

    // bubble_sort(arr,n);

    // insertion_sort(arr,n);



    
    
    
    return 0;
}