#include<bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node* next;

    node(int data1,node* next1){
        data=data1;
        next=next1;
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

int size_LL(node* head){
    int cnt=0;
    node* temp=head;
    while (temp!=nullptr)
    {
        cnt++;
        temp=temp->next;
    }
    return cnt;  
}

node* add_numbers_in_LL(node* head1,node* head2){

    node* dummyNode=new node(-1);
    node* curr=dummyNode;
    int carry=0;
    node* temp1=head1;
    node* temp2=head2;

    while (temp1!=nullptr || temp2!=nullptr)
    {
        int sum=carry;
        if(temp1){
            sum=sum+temp1->data;
        }
        if(temp2){
            sum=sum+temp2->data;
        }

        node* newnode=new node(sum%10);
        carry=sum/10;

        curr->next=newnode;
        curr=curr->next;

        if(temp1){
            temp1=temp1->next;
        }
        if(temp2){
            temp2=temp2->next;
        }
    }
    
    if(carry){
        node* newnode= new node(carry);
        curr->next=newnode;
    }

    return dummyNode->next;

}

node* odd_even_LL(node* head){
    // node* dummynode1= new node(-1);
    // node* dummynode2=new node(-1);
    // node* curr1=dummynode1;
    // node* curr2=dummynode2;
    // node* temp=head;

    // while (temp!=nullptr)
    // {
    //     curr1->next=new node(temp->data);
    //     curr1=curr1->next;
    //     temp=temp->next;
    //     if(temp!=nullptr){
    //     curr2->next=new node(temp->data);
    //     curr2=curr2->next;
    //     temp=temp->next;
    //     }
    // }
    // curr1->next=dummynode2->next;
    // return dummynode1->next;
    

    node* odd=head;
    node* even=head->next;
    node* evenhead=head->next;
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    while (even!=nullptr && even->next!=nullptr)
    {
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;   
    }
    odd->next=evenhead;
    return head;
} 

node* sort_LL_of_0_1_2(node* head){

    if(head==nullptr || head->next==nullptr){
        return head;
    }
    node* dummynode0=new node(-1);
    node* curr0=dummynode0;
    node* dummynode1=new node(-1);
    node* curr1=dummynode1;
    node* dummynode2=new node(-1);
    node* curr2=dummynode2;
    node* temp=head;

    while (temp!=nullptr)
    {
        if(temp->data==0){
            curr0->next=temp;
            curr0=temp;
        }
        else if(temp->data==1){
            curr1->next=temp;
            curr1=temp;
        }
        else{
            curr2->next=temp;
            curr2=temp;
        }
        temp=temp->next;
    }
    curr0->next=(dummynode1->next)?dummynode1->next:dummynode2->next;
    curr1->next=dummynode2->next;
    curr2->next=nullptr;
    return dummynode0->next;
}

node* remove_nth_node_from_the_back(node* head,int n){

    
}
int main(){
    vector<int> arr={2 ,5, 6, 8, 9, 1};
    vector<int> arr2={0,0,1,2,1,0,2,1,0};
    node* head1=convert_array_to_linked_list(arr);
    node* head2=convert_array_to_linked_list(arr2);

    // node* head=add_numbers_in_LL(head1,head2);
    // linked_list_traversal(head);

    // node* head=odd_even_LL(head1);
    // linked_list_traversal(head);

    // node* head=sort_LL_of_0_1_2(head2);
    // linked_list_traversal(head);

    node* head=remove_nth_node_from_the_back(head,3);
    linked_list_traversal(head);

    return 0;
}