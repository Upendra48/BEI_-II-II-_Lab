// Implementation of Queue using array in C++


#include <iostream>
using namespace std;

class Queue {
    
    public:
        int *arr;
        int front;
        int rear;
        int size;
        
    Queue( int size ) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
        
    void enqueue(int element){
        if(front==-1 && rear==-1){
            front++;
            rear++;
            arr[rear] = element;
            cout<<element<<" :Element enqueued"<<endl;
        }
        else if(rear<size-1){
            rear++;
            arr[rear] = element;
            cout<<element<<" :Element enqueued"<<endl;
        }
        else{
            cout << "Queue Overflow" << endl;
        }
    }
    void dequeue(){
        if(front<=rear){
            cout<<arr[front]<<" :Element dequeued"<<endl;
            front++;
            
        }
        else{
            cout << "Queue Underflow" << endl;
        }
    }
    
    int peek(){
        if(front<=rear){
            cout<<arr[front]<<" :Front of the queue"<<endl;
            return arr[front];
            
        }
        else{
            cout << "Queue is empty" << endl;
        }
    }
    bool isEmpty(){
        return (front>rear);
    
    }
    
};

int main(){
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    
    cout << q.peek()<<endl;
    q.dequeue();
    cout << q.peek()<<endl;
    

    return 0;
}