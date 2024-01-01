// Implementation of circular linked list

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }    
};

int main(){
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);

    node1->next = node2;
    node2->next = node3;
    node3->next = node1;
    
    cout<< node1->data <<endl;
    cout<< node1->next->data <<endl;
    cout<< node1->next->next->data <<endl;
    cout<< node1->next->next->next->data <<endl;
    return 0;
}