// Reverse a Stack using recursion

#include <bits/stdc++.h>
using namespace std;

void insertAtBottom( stack<int> &s,int element){
    // Base case
    if(s.empty()){
        s.push(element);
        return;
    }

    // recursive case
    int y = s.top();
    s.pop();
    insertAtBottom(s,element);
    s.push(y);
}

void ReverseStack(stack<int> & st){
    // Base case
    if(st.empty()){
        return;
    }

    // recursive case
    int x = st.top();
    st.pop();
    ReverseStack(st);
    insertAtBottom(st,x);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    ReverseStack(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}