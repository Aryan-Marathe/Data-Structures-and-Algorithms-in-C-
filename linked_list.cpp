#include<bits/stdc++.h>
using namespace std;

class node{

    int data;
    node* next;

    node(int data1,node* next1){
        data=data1;
        next=next1
    }

    node(int data1){
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

void linked_list_traversal(node* head){

    node* temp=head;
    while (temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

node* add_numbers_in_LL(node* head1,node* head2){

    int carry=0;
        node* sum=new node(head1->data+head2->data+carry);
        node* newhead=sum;
        carry=(head1->data+head2->data+carry)%10;
        node* temp1=head1->next;
        node* temp2=head2->next;
        while(temp1!=nullptr && temp2!=nullptr){
            if(temp1==nullptr){
                temp1->data=0;
                node* sum=new node(temp1->data+temp2->data+carry);
                carry=(temp1->data+temp2->data+carry)%10;
            }
            else if(temp2==nullptr){
                temp2->data=0;
                node* sum=new node(temp1->data+temp2->data+carry);
                carry=(temp1->data+temp2->data+carry)%10;
            }
            else{
                node* sum=new node(temp1->data+temp2->data+carry);
                carry=(temp1->data+temp2->data+carry)%10;
            }
        }
    return newhead;
}

int main(){
    vector<int> arr={2 ,5, 6, 8, 9, 1};
    vector<int> arr2={3,4,7,1,9,2};
    node* head1=convert_array_to_linked_list(arr);
    node* head2=convert_array_to_linked_list(arr2);

    head=add_numbers_in_LL(head1,head2);
    linked_list_traversal(head);

    return 0;
}