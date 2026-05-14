#include<bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node* left;
    node* right;

    node(int data1){
        data=data1;
        left=nullptr;
        right=nullptr; 
    }
};

node* insertLevelOrder(int arr[], int i, int n) {
    node* root = nullptr;
    // Base case for recursion
    if (i < n) {
        root = new node(arr[i]);
        // Insert left child
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        // Insert right child
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

node* preorder(node* root){
    if(root==nullptr){
        return root;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

node* postorder(node* root){
    if(root==nullptr){
        return root;
    }
   
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

node* inorder(node* root){
    if(root==nullptr){
        return root;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);   
}


int main(){
 
    vector<int> arr={1,4,7,3,8,2,9,0};
    int n=arr.size();
    node* root = insertLevelOrder(arr.data(),0,n);

    // preorder(root);

    // postorder(root);

    // inorder(root);
    return 0;
}
