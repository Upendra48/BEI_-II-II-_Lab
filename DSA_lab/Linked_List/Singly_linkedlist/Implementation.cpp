
//todo:  Implementation of Singly linked list

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
    Node* head = new Node(10);
    Node* temp1 = new Node(20);
    head -> next = temp1;

    cout<< head->data <<endl;
    cout<< head->next->data <<endl;
   
    return 0;
}

