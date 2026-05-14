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

Dnode* delete_all_ocuurances_of_key(Dnode* head,int key){

      Dnode* temp=head;
      while (temp!=nullptr)
      {
        if(temp->data==key){
            if(temp==head){
                head=head->next;
            }
            Dnode* nextNode=temp->next;
            Dnode* prevNode=temp->prev;
            if(nextNode){
                nextNode->prev=prevNode;
            }
            if(prevNode){
                prevNode->next=nextNode;
            }
            delete temp;
            temp=nextNode;
        }
        else{
            temp=temp->next;
        }
      }
      return head;
}

void find_pairs_with_given_sum(Dnode* head,int sum){
   
    if(head==nullptr || head->next==nullptr){
        cout<<0;
    }
   vector<pair<int,int>> vec;
   Dnode* front=head;
   Dnode* back=head;
   
   while (back->next != nullptr)
   {
    back=back->next;
   }
   
   while (front!=back &&front->prev!=back)
   {
    int val_sum=front->data+back->data;
    if(val_sum==sum){
        vec.push_back({front->data,back->data});
    }
    else if(val_sum>sum){
        back=back->prev;
    }
    else{
        front=front->next;
    }
   }
   for ( auto it : vec)
   {
    cout<<it.first<<" "<<it.second<<endl;
   }
   
}

Dnode* remove_duplicates_from_sortedDLL(Dnode* head){

    Dnode* temp=head;
    while (temp!=nullptr && temp->next!=nullptr)
    {
        Dnode* nextnode=temp->next;
        while (nextnode!=nullptr && nextnode->data==temp->data)
        {
            Dnode* duplicate=nextnode;
            nextnode=nextnode->next;
            delete duplicate;
        }
        
        temp->next=nextnode;
        if(nextnode->next!=nullptr){
            nextnode->prev=temp;
        }
        temp=temp->next;
    }
    return head;
}
int main(){
    vector<int> arr={1,1,2,3,3,3,4,9};
    Dnode* head=create_DLL(arr);

    // head=reverse_DLL(head);
    // DLL_traversal(head);

    // head=delete_all_ocuurances_of_key(head,9);
    // DLL_traversal(head);

    // find_pairs_with_given_sum(head,5);

    head=remove_duplicates_from_sortedDLL(head);
    DLL_traversal(head);
    
     return 0;
}