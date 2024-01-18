// Implementation of Binary Tree

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
};

Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int printNode(Node* root){
    if(root == NULL){
        return 0;
    }
    cout<<root->data<<" ";
    printNode(root->left);
    printNode(root->right);
}

int main(){
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    
    root->left->left = createNode(4);

    printNode(root);
    return 0;
}