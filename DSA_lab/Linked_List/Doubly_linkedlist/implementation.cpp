//todo: Implementation of Doubly linked list

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *prev;

    Node(int data){    //? constructor
        this-> data = data;
        this-> next = NULL;
        this-> prev = NULL;
    }
};

int main(){
    Node* node1 = new Node(10);
    //node1->data = 10;
    node1->prev = NULL;

    Node* node2 = new Node(20);
    //node2->data = 20;
    //node2->prev = node1;
    node2->next = NULL;

    node1->next = node2;
    cout<< node1->data <<endl;
    cout<< node1->next->data <<endl;
    
    return 0;
}