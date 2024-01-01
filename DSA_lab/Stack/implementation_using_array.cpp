// Implementation of Stack using array in C++

#include <iostream>
using namespace std;
class Stack {
    
    public:
        int *arr;
        int top;
        int size;
        
    Stack( int size ) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }    
    void push(int element){
        if(size-top>1){
            top++;
            arr[top] = element;
            cout<<element<<" pushed into stack"<<endl;
        }
        else{
            cout << "Stack Overflow" << endl;
        }
    }
    void pop(){
        if(top>=0){
            cout<<arr[top]<<" :Element popped"<<endl;
            top--;
            
        }
        else{
            cout << "Stack Underflow" << endl;
        }
    }
    
    int peek(){
        if(top>=0){
            cout<<arr[top]<<" :Top of the stack"<<endl;
            return arr[top];
            
        }
        else{
            cout << "Stack is empty" << endl;
        }
    }
    bool isEmpty()
    {
        return top<0?true:false;
    }
};


int main() {
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    
    cout << st.peek()<<endl;

    st.push(50);

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    cout << st.isEmpty() << endl;
    return 0;
}