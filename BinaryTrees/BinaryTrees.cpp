#include<iostream>
#include<queue>
#include"BinaryTreeNode.h"
using namespace std;

// Elements between root to given node
vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data){
    if(root == NULL)
        return NULL;
    if(root->data == data){
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int>* leftOutput = getRootToNodePath(root->left, data);
    if(leftOutput != NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int>* rightOutput = getRootToNodePath(root->right, data);
    if(rightOutput != NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    }else{
        return NULL;
    }
}
// Height and Diameter
// Return type of function is inbuilt pair type
pair<int,int> HeightDiameter(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<int,int> p;
        p.first = 0; // i.e height=0
        p.second = 0; // i.e diameter=0
        return p;
    }
    pair<int,int> leftAns = HeightDiameter(root->left);
    pair<int,int> rightAns = HeightDiameter(root->right);
    int ld = leftAns.second;
    int rd = rightAns.second;
    int lh = leftAns.first;
    int rh = rightAns.first;

    int height = 1+max(lh,rh);
    int diameter = max(lh+rh, max(ld,rd));
    pair<int,int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

// Helper function
BinaryTreeNode<int>* PostInHelper(int *post, int *in, int postS, int postE, int inS, int inE){
    if(postS > postE) // or inS>inE
        return NULL;
    int rootData = post[postE];
    int rootIndex = -1;
    for(int i=inS;i<=inE;i++){
        if(in[i]==rootData){
            rootIndex = i;
            break;
        }
    }
    int lInS = inS;
    int lInE = rootIndex -1;
    int lPostS = postS;
    int lPostE = lPostS + lInE-lInS;
    int rInS = rootIndex+1;
    int rInE = inE;
    int rPostS = lPostE+1;
    int rPostE = postE - 1;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = PostInHelper(post, in, lPostS, lPostE, lInS, lInE);
    root->right = PostInHelper(post, in, rPostS, rPostE, rInS, rInE);
    return root;
}
// Construct tree using PostOrder and Inorder
BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    return PostInHelper(postorder, inorder, 0, postLength-1, 0, inLength-1);
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
    /*int post[] = {4,5,2,8,9,6,7,3,1};
    int in[] = {4,2,5,1,8,6,9,3,7};
    BinaryTreeNode<int>* root = getTreeFromPostorderAndInorder(post, 9, in, 9);
    printTreeLevelWise(root);
    cout<<numNodes(root)<<endl;
    cout<<"Height : "<<HeightDiameter(root).first<<", Dia: "<<HeightDiameter(root).second<<endl;
    */
    cout<<endl;
    printTreeLevelWise(root);
    vector<int>* output = getRootToNodePath(root,3);
    for(int i=0;i<output->size(); i++){
        cout<<output->at(i)<<endl;
    }
    delete output;
    delete root; //delete whole tree. See destructor
}
