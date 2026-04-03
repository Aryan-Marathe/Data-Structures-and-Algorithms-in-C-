#include<bits/stdc++.h>
using namespace std;

class node{
    // we can use struct as well but struct does not give oop properties so class is better 
        public:
        // A SELF DEFINE DATATYPE NODE WHICH STORES DATA AND THE NEXT POINTER
        int data; // data of the node
        node* next; //next pointer to the next node
        public:
        node(int data1,node* next1){  // CONSTRUCTOR
            data=data1;
            next=next1;
        }
         node(int data1){  //automatically gets next pointer as null so no to define null again in line 25
            data=data1;
            next=nullptr;
         }
    };   


node* convert_array_to_linked_list(vector<int> &arr){

        node* head= new node(arr[0]);
        node *mover= head;
        for(int i=1;i<arr.size();i++){
            node* temp= new node(arr[i]);
            mover->next=temp;
            mover=temp;
        }
        return head;
    }

node* linked_list_traversal(node* head){

    node* temp=head;
    while (temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int lenght_of_linked_list(node* head){

    int cnt=0;
    node* temp=head;
    while (temp)
    {
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

bool search_in_linked_list(node* head,int value){

    node*temp=head;
    while (temp)
    {
       if(temp->data==value){
        return true;
       }
       else{
        temp=temp->next;
       }
    }

    return false;   
}

node* delete_head_linked_list(node* head){

    if(head==nullptr){
        return head;
    }
    node* temp=head;
    head=head->next;
    free(temp);
    return head;    
}

node* delete_last_ele_linked_list(node* head){

    if(head==nullptr || head->next==nullptr){
        return NULL;
    }
    node* temp=head;
    while (temp->next->next !=nullptr)
    {
       temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;
    return head;
    
}

node* delete_by_position(node* head,int k){

    if(head==nullptr){
        return nullptr;
    }
    if(k>lenght_of_linked_list(head)){
        return head;
    }
    else if(k==1){
        node* temp=head;
        head=temp->next;
        free(temp);
        return head;
    }
    else if(k==lenght_of_linked_list(head)){
        node* temp=head;
        while (temp->next->next !=nullptr)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=nullptr;
        return head;
    }
    else{
        node* temp=head;
        node* prev=nullptr;
        int cnt=0;
        while (temp!=nullptr)
        {
            cnt++;
            if(cnt==k){
            prev->next=prev->next->next;
            free(temp);
            break;
            }
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

node* delete_by_val(node* head,int val){

    //do again

    if(head==nullptr){
        return head;
    }
    node*temp=head;
    while (temp)
    {
        cout<<"hiii";
        if(temp->next->data==val){
            temp->next=temp->next->next;
            free(temp);
        }
        else{
            temp=temp->next;
        }
    }
    return head;  
}

node* insert_at_the_head(node* head,int ele){

    node* temp=new node(ele);
    temp->next=head;
    head=temp;
    return head;
}

node* insert_at_last(node* head,int ele){
    node* temp=new node(ele);

    if(head==nullptr){
        return temp;
    }
    node* temp1=head;
    while (temp1->next!=nullptr)
    {
        temp1=temp1->next;
    }
    
    temp1->next=temp;
    temp->next=nullptr;
    return head;
}

node* insert_at_position(node* head,int k,int ele){

    if(head=nullptr){
        if(k==1){
            return new node(ele);
        }
        else{
            return head;
        }
    }

    if(k==1){
        return new node(ele,head);
    }
    int cnt=0;
    node* temp=head;
    while (temp!=nullptr)
    {
        if(cnt=(k-1)){
        node* x=new node(ele);
        x->next=temp->next;
        temp->next=x;
        break;
    }
    temp=temp->next;
    }   
    return head;
}

node* insert_before_value(node* head,int val,int ele){

    if(head=nullptr){
        return nullptr;
    }

    if(head->data==val){
        return new node(ele,head);
    }
    
    node* temp=head;
    while (temp->next!=nullptr)
    {
        if(temp->next->data==val){
        node* x=new node(ele);
        x->next=temp->next;
        temp->next=x;
        break;
    }
    temp=temp->next;
    }   
    return head;
}

int main(){
    vector<int> arr={2 ,5, 6, 8, 9, 1};

    //  node* y = new node(arr[0],nullptr); // creating a new node in the linked list

    //  cout<<y<<endl; //printing the address of the node

    //  cout<<y->data<<endl; //printing the data stored in the node

    //  cout<<y->next<<endl; //printing the address of the next node

    node* head=convert_array_to_linked_list(arr);

    // cout<<head->data; //printing the head data of the linked list 

    // cout<<linked_list_traversal(head);
    
    // cout<<lenght_of_linked_list(head);

    // cout<<search_in_linked_list(head,2);

    // head=delete_head_linked_list(head);
    // linked_list_traversal(head);

    // head=delete_last_ele_linked_list(head);
    // linked_list_traversal(head);

    // head=delete_by_position(head,3);
    // linked_list_traversal(head);

    // head=delete_by_val(head,8);
    // linked_list_traversal(head);

    // head=insert_at_the_head(head,0);
    // linked_list_traversal(head);

    // head=insert_at_last(head,99);
    // linked_list_traversal(head);

    // head=insert_at_position(head,6,2);
    // linked_list_traversal(head);

    // head=insert_before_value(head,3,4);
    // linked_list_traversal(head);

    return 0;
}