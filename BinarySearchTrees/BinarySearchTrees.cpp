#include<iostream>
#include<queue>
#include"BinarySearchTreeNode.h"
#include"BinarySearchTreeClass.h"
using namespace std;

/* ======== Check if given tree Binary Search tree or not ========*/

/* ================= Way 1 --> O(n*h) Complexity  ===============*/
int minimum(BinaryTreeNode<int>* root){
    if(root==NULL)
        return INT_MAX;
    return min(root->data, min(minimum(root->left),minimum(root->right)));

}
int maximum(BinaryTreeNode<int>* root){
    if(root==NULL)
        return INT_MIN;
    return max(root->data, max(maximum(root->left),maximum(root->right)));
}
bool isBST(BinaryTreeNode<int>* root){
    if(root==NULL)
        return true;
    int leftmax = maximum(root->left);
    int rightmin = minimum(root->right);
    return (root->data > leftmax) && (root->data < rightmin) && isBST(root->left) && isBST(root->right);
}
/* =================================================================*/

/* ================== Way 2 --> O(n) Complexity  =================*/
/* ====================== Bottom - Up Approach ===================*/
class isBSTReturn{
public:
    bool isBST;
    int minimum;
    int maximum;
};
isBSTReturn isBST2(BinaryTreeNode<int>* root){
    if(root==NULL){
        isBSTReturn output;
        output.isBST = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }
    isBSTReturn leftOutput = isBST2(root->left);
    isBSTReturn rightOutput = isBST2(root->right);
    int minimum = min(root->data, min(leftOutput.minimum, rightOutput.minimum));
    int maximum = max(root->data, max(leftOutput.maximum, rightOutput.maximum));
    bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST;
    isBSTReturn output;
    output.isBST = isBSTFinal;
    output.maximum = maximum;
    output.minimum = minimum;
    return output;
}

/* ================== Way 3 --> O(n) Complexity ======================*/
/* ====================== TOP-Down Approach ==========================*/
bool isBST3(BinaryTreeNode<int>* root, int min_=INT_MIN, int max_=INT_MAX){
    if(root==NULL)
        return true;
    if(root->data < min_ || root->data > max_)
        return false;
    bool isLeftOk = isBST3(root->left, min_, root->data-1);
    bool isRightOk = isBST3(root->right, root->data, max_);
    return isLeftOk && isRightOk;
}
/*  =================================================================*/


// Find path from root to given node
vector<int>* findPath(BinaryTreeNode<int> *root , int data){
    if(root == NULL)
        return NULL;
    if(root->data == data){
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }else if(root->data < data){
        vector<int>* rightOutput = findPath(root->right, data);
        if(rightOutput != NULL){
            rightOutput->push_back(root->data);
            return rightOutput;
        }
    }else{
        vector<int>* leftOutput = findPath(root->left, data);
        if(leftOutput != NULL){
            leftOutput->push_back(root->data);
            return leftOutput;
        }
    }
}


BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int> *root , int k){
    if(root == NULL)
        return NULL;
    if(root->data == k){
        return root;
    }else if(k > root->data){
        return searchInBST(root->right,k);
    }else{
        return searchInBST(root->left,k);
    }
}

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

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
// 4 2 6 1 30 5 7 -1 -1 -1 -1 -1 -1 -1 -1
int main(){
    /*
    BinaryTreeNode<int>* root= takeInputLevelWise();
    //printTreeLevelWise(root);
    cout<<isBST(root)<<endl;
    cout<<isBST2(root).isBST<<endl;
    cout<<isBST3(root)<<endl;
    delete root;
    */
    BST b;
    b.insertNode(10);
    b.insertNode(5);
    b.insertNode(20);
    b.insertNode(7);
    b.insertNode(3);
    b.insertNode(15);
    b.printTree();
    b.deleteData(10);
    b.deleteData(100);
    b.printTree();
}
