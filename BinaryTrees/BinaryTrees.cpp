#include<iostream>
#include<queue>
#include"BinaryTreeNode.h"
using namespace std;

// Input Level Wise
BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter data : ";
    cin>>rootData;
    if(rootData == -1)
        return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        int leftChild;
        cout<<"Enter left child of "<<front->data<<" : ";
        cin>>leftChild;
        if(leftChild != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChild);
            front->left = child;
            pendingNodes.push(child);
        }
        int rightChild;
        cout<<"Enter right child of "<<front->data<<" : ";
        cin>>rightChild;
        if(rightChild != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChild);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter data : ";
    cin>>rootData;
    if(rootData == -1)
        return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

// Inorder Traversal  left->root->right
void inorder(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
// Postorder Traversal left->right->root
void postorder(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
// Preorder Traversal root->left->right
void preorder(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int numNodes(BinaryTreeNode<int>* root){
    if(root == NULL)
        return 0;
    return 1+numNodes(root->left)+numNodes(root->right);
}

// Height of binary Tree
int height(BinaryTreeNode<int> *root) {
    if(root == NULL)
        return 0;
    int left_height = height(root->left);
    int right_height = height(root->right);
    return (left_height>right_height) ? left_height+1 : right_height+1; // +1 for root node

}

// Print Level Wise
void printTreeLevelWise(BinaryTreeNode<int>* root){
    if(root==NULL)
        return;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        if(front->left != NULL){ // or if(front->left){
            cout<<"L:"<<front->left->data;
            pendingNodes.push(front->left);
        }
        if(front->right){ // or if(front->right != NULL){
            cout<<",R:"<<front->right->data;
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}
void printTree(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    cout<<root->data<<" : ";
    if(root->left != NULL)
        cout<<"L:"<<root->left->data<<",";
    if(root->right != NULL)
        cout<<"R:"<<root->right->data;
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){
    //BinaryTreeNode<int>* root = takeInput();
    BinaryTreeNode<int>* root = takeInputLevelWise();
    //printTree(root);
    printTreeLevelWise(root);
    cout<<numNodes(root)<<endl;
    cout<<"Height : "<<height(root)<<endl;
    delete root; //delete whole tree. See destructor
}
