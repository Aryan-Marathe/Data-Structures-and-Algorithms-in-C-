#include<bits/stdc++.h>
using namespace std;

//PAIRS

void explain_pairs()
{
    pair<int,int> p = {1,3};
    cout<<p.first<<" "<<p.second<<endl;  //ouput 1,3
    cout<<"______________"<<endl;

    pair<int,pair<int,int>> q= {2,{4,5}};
    cout<<q.first<<" "<<q.second.first<<" "<<q.second.second<<endl; //output 2,4,5
    cout<<"______________"<<endl;

    pair<int,int> arr[]={{2,3},{5,6},{9l,7}};
    cout<<arr[1].first<<endl;
    cout<<"______________"<<endl; //output 5
    
}

//VECTORS


void explain_vector()
{
  vector<int> vec1;  //declaration of vector and vector is dynamic in size 
  vec1.push_back(1); //push 1 in the vector 
  vec1.emplace_back(3); //push 3 in the vector
  vec1.emplace_back(5); //push 5 in the vector
  vec1.emplace_back(7); //push 7 in the vector
  vec1.emplace_back(2); //push 2 in the vector
  
  vector<pair<int,int>> vec2; //vector with pairs
  vec2.push_back({1,2}); //push the {1,2} in the vector 
  vec2.emplace_back(4,5); //push (4,5) in the vector 
  vec2.emplace_back(6,7); //push (6,7) in the vector 
  vec2.emplace_back(9,4); //push (9,4) in the vector 
  vec2.emplace_back(10,19); //push (10,19)in the vector 

  vector<int> vec3(5,100); //creates a vector of size 5 with 100 at all the places 
  
  vector<int> vec4(4);  //creates a vector of size 4 with 0 or garbage value in it 

  vector<int> vec5(3,40);
  vector<int> vec6(vec5); //creates a copy of the vec5 with name vec6


  cout<<"first way of accessing : "<<vec1[0]<<endl; //output = 1
  cout<<"___________"<<endl;

 vector<int> :: iterator it1= vec1.begin(); //creates a iterator which points to the starting address of the vector vec1
 cout<<*(it1)<<endl; //output = 1
 cout<<"__________"<<endl;

 vector<int> :: iterator it2 =vec1.end(); //creates a iterator which points to the address just after the last element

 cout<<vec1.back()<<endl; //prints the last element in the vector here output = 2
 cout<<"_____________"<<endl; 


 //ACCESSING THE ELEMENETS IN THE VECTOR WITH THE FOR LOOP

 for(auto it3=vec1.begin();it3!=vec1.end();it3++){

    cout<<*(it3)<<" ";
 }

 cout<<endl;
 cout<<"_________"<<endl;


 for(auto it4 : vec1){

    cout<<it4<<" ";

 }

 cout<<endl;
 cout<<"__________________"<<endl;


 vec1.erase(vec1.begin()+1); //element 3 gets deleted from vector vec1
 for(auto it=vec1.begin();it!=vec1.end();it++){
    cout<<*(it);
 }
cout<<endl;
cout<<"_______________"<<endl;


vec3.erase(vec3.begin()+1,vec3.begin()+3); //deletes the element at 1st and 2nd place 
for(auto it=vec3.begin();it!=vec3.end();it++){

   cout<<*(it)<<" ";
}

cout<<endl;
cout<<"________________";

vector<int> vec7(2,22);
vec7.insert(vec7.begin(),3); //inserts 3 at starting of the vector 

for(auto it = vec7.begin();it!=vec7.end();it++){

    cout<<*(it)<<" ";
}
cout<<endl;
cout<<"__________";

cout<<vec1.size()<<endl; //gives the size of the vector 
cout<<"___________"<<endl;

vec1.pop_back(); //pops the last elemnet of the vector 

vec1.swap(vec3); //swaps the vectors

vec2.clear(); //erasses all the elements from the vector 

cout<<vec2.empty(); //returns true if vector is empty 
cout<<endl;

}


void explain_list(){

    list<int> ls; //creates a list ls

    ls.emplace_back(3); //adds the element 3 in the list
    ls.push_back(5); //adds the element 5 in the list 
    
    ls.push_front(1); //adds the element at the starting position of the list
    ls.emplace_front(9); //adds the element at the starting position of the list

    for(auto it = ls.begin();it!=ls.end();it++){

        cout<<*(it)<<" ";

    }
     cout<<endl;
    cout<<"_________";

    // rest of the function are same as the vectors
}


void explain_dequeue(){

    deque<int> dq;

    dq.push_back(1); //inserts 1 in the dequeue
    dq.emplace_back(2); //inserts 2 in the dequeue
    dq.push_front(3); //inserts 3 at the front of the dequeue
    dq.emplace_front(4); //inserts 3 at the front of the dequeue

    for(auto it=dq.begin();it!=dq.end();it++){

        cout<<*(it);

    }

    cout<<endl;
    cout<<"_____________";

    dq.pop_back(); //pops the last element of the dequeue
    dq.pop_front(); //pops the front element of the dequeue

    for(auto it=dq.begin();it!=dq.end();it++){

        cout<<*(it);

    }

    cout<<endl;
    cout<<"_____________";


    cout<<dq.back(); //gives the last element in the dequeue
    cout<<dq.front(); //gives the first element in the dequeue

    //rest of the fucntions are same as vector 

    
}

void explain_stack(){
    stack<int> st;

    st.push(1); //push the element in the stack
    st.push(4);
    st.push(5);
    st.push(2);
    st.push(7);
    
    cout<<st.top()<<endl; // gives the element at the top of the stack

    cout<<st.size()<<endl; //gives the size of the stack

    cout<<st.empty()<<endl; //returns true if stack is empty 

    stack<int> st1,st2;

    st1.swap(st2); //swaps the stack elements 

}

void explain_queue(){
    queue<int> q;
    q.push(2);
    q.push(3);
    q.push(5);

    cout<<q.back()<<endl; //prints the last element of the queue

    q.pop(); //pops the element for the queue

    cout<<q.front()<<endl; //prints the front element of the queue
}

void explain_set(){

    //IN SET ALL THE ELEMENTS ARE SORTED AND UNIQUE DUPLICATES ARE NOT ALLOWED

    set<int> st;
    st.insert(2); //{2}
    st.insert(1); //{1,2}
    st.insert(9); //{1,2,9} 
    st.insert(6); //{1,2,6,9}

    for(auto it=st.begin();it!=st.end();it++){

        cout<<*(it)<<" ";
    }
 cout<<endl;

 cout<<"___________________";

    //ALL THE OTHER FUNCTIONS ARE SAME AS VECTORS


    auto it =st.find(1); //returns the address of the element 1 in the set
    
    st.erase(2); //deletes the element from the set

    int cnt=st.count(9); //counts the number of occurances of the element 

    auto it1=st.lower_bound(2);
    auto it2=st.upper_bound(4);
}

void explain_multiset(){

    multiset<int> mst;

    //ALL THE FUNCTIONS ARE SAME AS THE SET BUT THE ONLY DIFFERANCE IS, THE MULTISET ALLOWES REPEATED ELEMENTS
}

void explain_unorderd_set()
{

    unordered_set<int> un_set;

    //EVERYTHING IS SAME AS THE SET BUT IT STORES UNIQUE ELEMENTS AND IN RANDOM ORDER

}

void explain_map(){

    //STORES UNIQUE KEYS IN SORTED ORDER OF KEY

    map<int,int> mp1;

    mp1.insert({1,10});  //{ key , value }
    mp1.insert({2,20});
    mp1.insert({3,30});
    mp1.insert({4,40});
    mp1.insert({5,50});


    for(auto it : mp1){

        cout<<"key="<<it.first<<" "<<"value="<<it.second<<" ";
    }

    cout<<endl;
    cout<<"__________________";
    cout<<endl;

    map<int,pair<int,int>>  mp2;

    mp2.insert({2,{3,4}});  //{ key, {value} }
    mp2.insert({3,{1,4}});
    mp2.insert({4,{3,7}});
    mp2.insert({5,{9,6}});
    mp2.insert({6,{1,0}});

    for(auto it:mp2){

        cout<<"key="<<it.first<<" "<<"value={"<<it.second.first<<","<<it.second.second<<"}";
    }

    cout<<endl;
    cout<<"__________________";
    cout<<endl;

    //similarly we can have a combination of {{key},value}

    auto it=mp1.find(3);
    cout<<it->second<<endl;

    auto it=mp1.lower_bound(2);
    auto it1=mp1.upper_bound(4);

    // other fuctions are same as vector  

} 


void explain_multimap(){

    //everything is same as map, only it can store multiple keys 
}



int main(){

    // explain_pairs();
    // explain_vector();
    // explain_list();
    // explain_dequeue();
    // explain_stack();
    // explain_queue();
    // explain_set();
    // explain_map();
}

