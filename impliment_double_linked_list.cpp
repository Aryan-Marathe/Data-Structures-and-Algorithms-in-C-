#include<bits/stdc++.h>
using namespace std;

class Dnode{

    public:
    int data;
    Dnode* next;
    Dnode* prev;

    Dnode(int data1,Dnode* next1=nullptr, Dnode* prev1=nullptr){
        data=data1;
        next=next1;
        prev=prev1;
    }
};

Dnode* create_DLL_from_array(vector<int> &arr){

    Dnode* head=new Dnode(arr[0]);
    Dnode* back=head;

    for(int i=1;i<arr.size();i++){
        Dnode* temp=new Dnode(arr[i]);
        temp->prev=back;
        temp->next=nullptr;
        back->next=temp;
        back=temp;
    }
    return head;
}

void DLL_traversal(Dnode* head){

    Dnode* temp=head;
    while (temp!=nullptr)
    {
       cout<<temp->data<<" ";
       temp=temp->next;
    }    
}

Dnode* delete_head(Dnode* head){

    if(head==nullptr || head->next==nullptr){
        return nullptr;
    }

    Dnode* temp=head;
    head=head->next;
    head->prev=nullptr;
    temp->next=nullptr;
    delete temp;
    return head;
}

Dnode* delete_tail(Dnode* head){

    if(head==nullptr || head->next==nullptr){
        return nullptr;
    }

    Dnode* temp=head;
    while (temp->next->next!=nullptr)
    {
        temp=temp->next;
    }
    Dnode* tail=temp->next;
    temp->next->prev=nullptr;
    temp->next=nullptr;
    free(tail);
    return head;    
}

Dnode* delete_at_position(Dnode* head,int k){

    Dnode* temp=head;
    int cnt=0;

    while (temp!=nullptr)
    {
       cnt++;
       if(cnt==k){
        break;
       }
       else{
        temp=temp->next;
       }
    }

    Dnode* front=temp->next;
    Dnode* back=temp->prev;

    if(front==nullptr){
        return delete_tail(head);
    }
    else if(back==nullptr){
        return delete_head(head);
    }
    else if(back==nullptr && front==nullptr){
        delete temp;
        return nullptr;
    }
    else{
        back->next=temp->next;
        front->prev=temp->prev;
        temp->next=nullptr;
        temp->prev=nullptr;
        delete temp;
        return head;
    }   
}

Dnode* delete_given_node(Dnode* head,int val){
    Dnode* temp=head;
    while (temp->next!=nullptr)
    {
        if(temp->data==val){
            break;
        }
        else{
            temp=temp->next;
        }
    }
    Dnode* front=temp->next;
    Dnode* back=temp->prev;
    if(front==nullptr){
        back->next==nullptr;
        temp->prev=nullptr;
        return head;
    }
    else{
        back->next=front;
        front->prev=back;
        temp->next=nullptr;
        temp->prev=nullptr;
        delete temp;
        return head;
    }   
}

Dnode* insert_before_head(Dnode* head,int val){
    Dnode* newNode=new Dnode(val);
    newNode->next=head;
    head->prev=newNode;
    newNode->prev=nullptr;
    head=newNode;
    return head;
}

Dnode* insert_before_tail(Dnode* head,int val){
    Dnode* newNode=new Dnode(val);
    Dnode* temp=head;

    if(head==nullptr){
        Dnode* newNode= new Dnode(val);
        return head;
    }

    else if(temp->next=nullptr){
        return insert_before_head(head,val);    
    }
    else{
    while (temp->next->next!=nullptr)
    {
        newNode->next=temp->next;
        newNode->prev=temp;
        temp->next->prev=newNode;
        temp->next=newNode;
        return head;
    }
}
}
int main(){

    vector<int> arr={2 ,5, 6, 8, 9, 1};

    Dnode* head=create_DLL_from_array(arr);
    // DLL_traversal(head);

    // head=delete_head(head);
    // DLL_traversal(head);

    // head=delete_tail(head);
    // DLL_traversal(head);

    // head=delete_at_position(head,3);
    // DLL_traversal(head);

    // head=delete_given_node(head,8);
    // DLL_traversal(head);

    // head=insert_before_head(head,10);
    // DLL_traversal(head);

    head=insert_before_tail(head,10);
    DLL_traversal(head);
    return 0;
}