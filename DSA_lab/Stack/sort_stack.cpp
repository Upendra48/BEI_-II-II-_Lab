// Sort a stack using recursion

#include <bits/stdc++.h>
using namespace std;

void SortedInsert(stack<int> &st,int element){
    // Base case
    if(st.empty() || st.top() < element){
        st.push(element);
        return;
    }

    // recursive case
    int x = st.top();
    st.pop();
    SortedInsert(st,element);
    st.push(x);
}

void reverseStack(stack<int> &st){
    // Base case
    if(st.empty()){
        return;
    }

    // recursive case
    int x = st.top();
    st.pop();
    reverseStack(st);
    SortedInsert(st,x);
}

int main(){
    stack <int> s;
    s.push(1);
    s.push(8);
    s.push(3);
    s.push(-4);
    reverseStack(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}