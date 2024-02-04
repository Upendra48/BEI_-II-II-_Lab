// Implementation of AVL tree

#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
        int data;
        int height;
        Node *left, *right;

    Node(int data){
        this->data = data;
        this->height = height;
        this->left = this->right = NULL;
    }    
};