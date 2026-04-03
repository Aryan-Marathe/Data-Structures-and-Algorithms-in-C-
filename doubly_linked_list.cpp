#include<bits/stdc++.h>
using namespace std;


class Dnode{
    public:
    int data;
    Dnode* next;
    Dnode* prev;
    public:
    Dnode(int data1,Dnode* next1,Dnode* prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }
    public:
    Dnode(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
};


Dnode* create_DLL(vector<int> &arr){
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

Dnode* reverse_DLL(Dnode* head){

    if(head==nullptr || head->next==nullptr){
        return head;
    }
    
    else {
        Dnode* front=head;
        Dnode* back=head;
        while (back->next!=nullptr)
        {
           back=back->next;
        }
        while (front<back)
        {
            swap(front->data,back->data);
            front=front->next;
            back=back->prev;
        }  
         return head; 
    }

    
}
int main(){
    vector<int> arr={2 ,5, 6, 8, 9, 1};
    Dnode* head=create_DLL(arr);

    head=reverse_DLL(head);
    DLL_traversal(head);
     return 0;
}