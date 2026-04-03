#include<bits/stdc++.h>
using namespace std;

class implement_stack_using_array{

    int top=-1;
    int st[10]; //stack of size 10

    void push(int x){
        if(top>=10){
            cout<<"overflow";
        }
        else{
            top++;
            st[top]=x;
        }
    }

    int top(){
        if(top==-1){
            cout<<"underflow";
        }
        else{
            return st[top];
        }
    }

    void pop(){
        if(top==-1){
            cout<<"underflow";
        }
        else{
            top--;
        }
    }

    int size(){
        return top+1;
    }
};

class imlement_queue_using_array{

    int start,end=-1;
    int size=10;
    int q[size];  //queue of size 10
    int current_size=0;

    void push(int x){
        if(current_size==size){
            cout<<"overflow";
        }
        if(current_size==0){
            start=0;
            end=0;
        }
        else{
            end=(end+1)%size;
            q[end]=x;
            current_size++;
        }
    }

    int pop(){
        if(current_size==0){
            cout<<"underflow";
        }

        int ele=q[start];

        if(current_size==1){
            start=-1;
            end=-1;
        }
        else{
            start=(start+1)%size;
        }
        current_size--;
        return ele; 
    }

    int top(){
        if(current_size==0){
            cout<<"undeflow";
        }
        else{
            return q[start];
        }
    }

    int size(){
        return current_size;
    }

};

class impement_satck_using_linked_list{

    node*top;
    int size=0;

    void push(int x){
        node*temp=new node(x);
        temp->next=top;
        top=temp;
        size++;
    }

    void pop(){
        node*temp=top;
        top=top->next;
        delete temp;
        size--;
    }

    int top(){
        return top->data;
    }

    int size(){
        return size;
    }
};

class implement_queue_using_linked_list{
    node*start,end;
    size=0;

    void push(int x){
        node*temp=new node(x);

        if(start==NULL){
            start=end=temp;
        }
        else{
            end->next=temp;
        }
        size++;
    }

    void pop(){
        if(start==NULL){
            cout<<"undeflow";
        }
        temp=start;
        start=start->next;
        delete temp;
        size--;
    }

    int top(){
        if(start==NULL){
            cout<<"underflow";
        }
        return start->val;
    }

    int size(){
        return size;
    }

};

class implement_stack_using_queue{

    queue<int> q;
    int push(int x){
    int size=q.size();
    for(int i=1;i<size;i++){
        q.push(q.front());
        q.pop();
    }
}

int pop(){
    q.pop();
}

int top(){
    return q.front();
}

int size(){
    return q.size()''
}
};

class implement_queue_using_stack{

    stack<int> st1;
    stack<int> st2;

    void push(int x){
        while (st1.size())
        {
            st2.push(st1.top());
            st1.pop();
        }
        
        st1.push(x);

        while (st2.size())
        {
            st1.push(st2.top());
            st2.pop();
        }
        
    }

    int top(){
        return st1.top();
    }

    int pop(){
        return st1.pop();
    }

    int size(){
        return st1.size();
    }

};

class implement_queue_using_stack_optimal{

    stack<int> st1,st2;

    void push(int x){
        st1.push(x);
    }

    void pop(){
        if(st2.empty()!=0){
            st2.pop();
        }
        else{
            while (st1.size())
            {
                st2.push(st1.top());
                st1.pop();
            }
            st2.pop();
        }
    }

    int top(){
        if(st2.empty()!=0){
            return st2.top();
        }
        else{
            while (st1.size())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }
};

class min_stack{

    stack<pair<int,int>> st;
    void push(int x){
        if(st.empty()){
            st.push({x,x});
        }
        else{
            st.push({x,min(x,st.top().second)});
        }
    }

    int pop(){
        return st.pop();
    }

    int get_min(){
        return st.top().second;
    }

    int top(){
        return st.top().first;
    }
}


int main(){


    return 0;
}