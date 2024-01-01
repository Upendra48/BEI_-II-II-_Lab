// Implementation of Stack using linked list in C++

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class Stack{
    Node *head;
    int size;

    public:
    Stack(){
        head = NULL;
        size = 0;
    }

    int getSize(){
        cout<<size<<" :Size of the stack"<<endl;
        return size;
    }

    bool isEmpty(){
        return size==0;
    }

    void push(int element){
        Node *newNode = new Node(element);
        newNode->next = head;
        head = newNode;
        size++;
    }

    int pop(){
        if(isEmpty()){
            return 0;
        }
        int ans = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
        cout<<ans<<" :Element popped"<<endl;
        return ans;
    }

    int top(){
        if(isEmpty()){
            return 0;
        }
        cout<<head->data<<" :Top of the stack"<<endl;
        return head->data;
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    //st.push(40);
    cout<<st.top()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.top()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.getSize()<<endl;
    cout<<st.isEmpty()<<endl;
    return 0;
}