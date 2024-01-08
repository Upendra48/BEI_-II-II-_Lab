

//todo: Operations in Singly linked list

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

void InsertAtHead(Node* &head, int data)    //? 1. Inserting a node at head
{
    //? create a new node
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node* &head, int data)    //? 2. Inserting a node at tail
{
    Node *temp = new Node(data);
    if(head == NULL)
    {
        head = temp;
        return;
    }
    Node *lastNode = head;
    while(lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }
    lastNode->next = temp;
}

void InsertAtPosition(Node* &head,int data,int pos){
    Node *temp = new Node(data);
    if(pos== 1 || head == NULL){
        InsertAtHead(head,data);
    }
    else{
        Node *curr = head;
        for(int i=1;i<pos-1 && curr != NULL;i++){
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }

}

void DeleteNode(int pos, Node* &head){   //? 4. Deleting a node at given position
    Node *ptr = head;
    for(int i=0; i<pos-2; i++){
        ptr = ptr->next;
    }
    Node *temp = ptr->next;
    ptr->next = temp->next;
    delete temp;
    cout<< "Node deleted successfully" <<endl;
}

void printNode(Node* head){
    Node *temp = head;
    while(temp != NULL){
        cout<< temp->data <<"->";
        temp = temp->next;
    }
    cout<< "NULL" <<endl;
}
void findLength(Node* head){
    Node *temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    cout<< "Length of the linked list is: " << count <<endl;

}

int main(){
    Node* head = NULL;
    InsertAtHead(head,10);
    InsertAtHead(head,20);
    InsertAtHead(head,30);
    InsertAtHead(head,40);

    printNode(head);
    InsertAtTail(head,50);
    InsertAtPosition(head, 60, 2);

    printNode(head);

    findLength(head);

    DeleteNode(2,head);

    findLength(head);

    printNode(head);



    return 0;
}