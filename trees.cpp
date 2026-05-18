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

vector<vector<int>> level_order(node* root){
    vector<vector<int>> ans;
    if(root==nullptr){
        return ans;
    }
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            node* root=q.front();
            q.pop();
            if(root->left!=nullptr){
                q.push(root->left);
            }
            if(root->right){
                q.push(root->right);
            }
            level.push_back(root->data);
        }
        ans.push_back(level);
    }
    return ans;
}

void pre_order_iterative(node* root){
    if(root==nullptr){
        return;
    }
    stack<node*> st;
    st.push(root);
    while (!st.empty())
    {
        node* curr=st.top();
        st.pop();
        cout<<curr->data<<" ";
        if(curr->right!=nullptr){
            st.push(curr->right);
        }
        if(curr->left!=nullptr){
            st.push(curr->left);
        }
    }
}

int max_depth(node* root){
    if(root==nullptr){
        return 0;
    }
    int left_height=max_depth(root->left);
    int right_height=max_depth(root->right);
    return 1+max(left_height,right_height);
}

int check_height(node* root){
    if(root==nullptr){
        return 0;
    }
    int left_height=check_height(root->left);
    if(left_height==-1) {
        return -1;
    }
    int right_height=check_height(root->right);
    if(right_height==-1) {
        return -1;
    }
    if(abs(left_height-right_height)>1){
        return -1;
    }
    return 1+max(left_height,right_height);
}

bool check_balanced_tree(node* root){

    /* the tree called balance binary tree when,
            
        height(left_sun_tree)-height(right_sun_tree)<=1
    */

    if(check_height(root)==-1){
        return false;
    }
    else{
        return true;
    }

}

int diameter=0;
int check_depth(node* root){
    if(root==nullptr){
        return 0;
    }

    int lh=check_depth(root->left);
    int rh=check_depth(root->right);

    diameter=max(diameter,lh+rh);
    return 1+max(lh,rh);
}
int find_diameter(node* root){

    // diameter of the tree is longest path from one node to another

    check_depth(root);
    return diameter;
}
int main(){
 
    vector<int> arr={1,4,7,3,8,2,9,0};
    int n=arr.size();
    node* root = insertLevelOrder(arr.data(),0,n);

    // preorder(root);

    // postorder(root);

    // inorder(root);

    // level_order(root);

    // pre_order_iterative(root);

    // cout<<max_depth(root);

    // cout<<check_balanced_tree(root);

    cout<<find_diameter(root);

    return 0;
}


