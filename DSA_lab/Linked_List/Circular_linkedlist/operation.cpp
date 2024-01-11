// Implementation of Circular linked list and operations on it

#include<iostream>
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

class Circular_linkedlist{
    public:
        Node *head;
        Node *tail;

        Circular_linkedlist(){
            head = NULL;
            tail = NULL;
        }

        void insert(int data){
            Node *n = new Node(data);
            if(head == NULL){
                head = n;
                tail = n;
                n->next = head;
            }
            else{
                tail->next = n;
                tail = n;
                tail->next = head;
            }
        }

        void insertAt(int data, int pos){
            Node *n = new Node(data);
            Node *temp = head;
            int i = 1;
            while(i < pos-1){
                temp = temp->next;
                i++;
            }
            n->next = temp->next;
            temp->next = n;
        }

        void deleteAt(int pos){
            Node *temp = head;
            int i = 1;
            while(i < pos-1){
                temp = temp->next;
                i++;
            }
            Node *t = temp->next;
            temp->next = t->next;
            delete t;
        }

        void display(){
            Node *temp = head;
            while(temp->next != head){
                cout<<temp->data<<"->";
                temp = temp->next;
            }
            cout<<temp->data<<endl;
        }

};

int main(){
    Circular_linkedlist l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.display();
    l.insertAt(10, 2);
    l.insertAt(5,3);
    l.deleteAt(3);
    l.display();
    return 0;
}