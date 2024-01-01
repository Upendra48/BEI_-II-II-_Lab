// Operations in Doubly Linked List

#include <iostream>
using namespace std;

class Node {
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

void InsertAtHead(Node* &head, int data)    //? 1. Inserting a node at head
{
    //? create a new node
    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void InsertAtTail(Node* &tail, int data)    //? 2. Inserting a node at tail
{
    Node *temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void InsertAtKth(Node* &head, int data, int k)    //? 3. Inserting a node at kth position or given position
{
    if(k == 1)
    {
        InsertAtHead(head, data);
        return;
    }
    else
    {
        Node *temp = head;
        for(int i = 0; i < k-2; i++)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(data);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        newNode->next->prev = newNode;
    }
}

void DeleteNode(int k, Node* &head)    //? 4. Deleting a node at kth position or given position
{
    Node *temp = head;
    if(k == 1)
    {
        head = temp->next;
        head->prev = NULL;
        delete temp;
        return;
    }
    else
    {
        for(int i = 0; i < k-2; i++)
        {
            temp = temp->next;
        }
        Node *temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next->prev = temp;
        delete temp2;
    }
}

void Display(Node* head)    //? 5. Displaying the linked list
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(){
    Node *node_1 = new Node(10);
    Node *head = node_1;
    Node *tail = node_1;

    //InsertAtHead(head, 10);
    InsertAtTail(tail, 20);
    InsertAtTail(tail, 30);
    InsertAtTail(tail, 40);
    InsertAtTail(tail, 50);
    InsertAtKth(head, 60, 3);
    Display(head);
    cout << endl;

    DeleteNode(3, head);
    Display(head);
    return 0;
}