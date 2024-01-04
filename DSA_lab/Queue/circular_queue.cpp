// Implementation of circular queue using array

#include <iostream>
using namespace std;

class Queue
{
public:
    int front;
    int rear;
    int size=5;
    int *Q;

    Queue(int size)
    {
        front = rear = 0;
        this->size = size;
        Q = new int[this->size];
    }
    void enqueue(int x);
    int dequeue();
    void display();
};

void Queue::enqueue(int x)
{
    if ((rear + 1) % size == front)
        cout << "Queue is Full" << endl;
    else
    {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}

int Queue::dequeue()
{
    int x = -1;
    if (front == rear)
        cout << "Queue is Empty" << endl;
    else
    {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}

void Queue::display()
{
    int i = front + 1;
    do
    {
        cout << Q[i] << flush;
        if (i < rear)
            cout << " <- " << flush;
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
    cout << endl;
}

int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    cout << q.dequeue() << endl;

    q.enqueue(60);

    q.display();

    cout<<q.dequeue()<<endl;

    q.display();
    
    cout<<q.dequeue()<<endl;
    q.display();

    q.enqueue(70);
    q.enqueue(80);

    q.display();
    return 0;
}