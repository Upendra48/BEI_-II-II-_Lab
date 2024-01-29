// Implementation of binary search tree

#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;

    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }    
};

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* insertBST(Node* root, int data) {

    // Base case
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data <= root ->data) {

        // left subtree
        root->left = insertBST(root ->left, data);
    }
    else {
        // right subtree
        root->right = insertBST(root ->right, data);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertBST(root, data);
        cin>>data;
    }
}

int minVal(Node* root){
    if(root == NULL){
        return -1;
    }
    if(root->left == NULL){
        return root->data;
    }
    return minVal(root->left);
}

int maxVal(Node* root){
    if(root == NULL){
        return -1;
    }
    if(root->right == NULL){
        return root->data;
    }
    return maxVal(root->right);
}

Node* deleteFromBST(Node* root, int val){

    // Base case
    if(root == NULL) {
        return root;
    }
    if(root->data == val){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // 1 child

        // right child is present
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // left child is present
        if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }


        // 2 child
        if(root->left != NULL && root->right != NULL){
            int min = minVal(root->right);
            root->data = min;
            root->right = deleteFromBST(root->right, min);
            return root;
        }

    }else if(val < root->data){
        // go search in left subtree
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        // go search in right subtree
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}



int main(){
    Node *root = NULL;
    cout<<"Enter data to create a BST : ";
    takeInput(root);

    cout<<"Minimum value in BST : "<<minVal(root)<<endl;
    cout<<"Maximum value in BST : "<<maxVal(root)<<endl;

    cout<<"Level Order Traversal : "<<endl;
    levelOrderTraversal(root);

    cout<<"Printing in order : "<<endl;
    inorder(root);

    cout<<endl<<"Enter the value to delete : ";
    int val;
    cin>>val;
    root = deleteFromBST(root, val);

    cout<<"Level Order Traversal : "<<endl;
    levelOrderTraversal(root);
    
    cout<<"In Order Traversal : "<<endl;
    inorder(root);

    return 0;

}