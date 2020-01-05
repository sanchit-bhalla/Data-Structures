#include<iostream>
#include<vector>
#include<queue>
#include"TreeNode.cpp"
using namespace std;

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter data : ";
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        int numChild;
        cout<<"Enter number of children of "<<front->data<<" : ";
        cin>>numChild;

        for(int i=0;i<numChild;i++){
            int childData;
            cout<<"Enter "<<i<<"th child of "<<front->data<<" : ";
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter data\n";
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    int n;
    cout<<"Enter number of children of "<<rootData<<" : ";
    cin>>n;
    for(int i=0;i<n;i++){
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

// Count Nodes
int  numNodes(TreeNode<int>* root){
    if(root==NULL)
        return 0;
    int ans = 1;
    for(int i=0;i<root->children.size();i++){
        ans += numNodes(root->children[i]);
    }
    return ans;
}
int sumOfNodes(TreeNode<int>* root) {
    if(root==NULL)
        return 0;
    int tree_sum = root->data; // Initially sum is root data
    for(int i=0;i<root->children.size();i++){
        tree_sum += sumOfNodes(root->children[i]);
    }
    return tree_sum;
}

// Return the node with maximum data
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    TreeNode<int>* max_ = root;
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* rec_max = maxDataNode(root->children[i]);
        if(rec_max->data > max_->data){
            max_ = rec_max;
        }
    }
    return max_;
}

// Return Height of Tree
int height(TreeNode<int>* root) {
    if(root==NULL)
        return 0;
    int max_height = 0;
    for(int i=0;i<root->children.size();i++){
        int rec_height = height(root->children[i]);
        if(rec_height > max_height){
            max_height = rec_height;
        }
    }
    return max_height+1; // +1 bcz of root node
}

// Print all nodes at level k or at depth k
void printAtLevelK(TreeNode<int>* root, int k){
    if(root==NULL)
        return;
    if(k==0){
        cout<<root->data<<endl;
        return;
    }
    for(int i=0;i<root->children.size();i++){
        printAtLevelK(root->children[i], k-1);
    }
}

// Return total number of leaves
int numLeafNodes(TreeNode<int>* root) {
    if(root==NULL)  // Edge case not the base case
        return 0;

    if(root->children.size() == 0){  //Base case
        return 1;
    }

    int sumOfLeaf = 0;
    for(int i=0;i<root->children.size(); i++){
        sumOfLeaf += numLeafNodes(root->children[i]);
    }
    return sumOfLeaf;
}

// Preorder traversal
void preorder(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
    }
}

void postorder(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        postorder(root->children[i]);
    }
    cout<<root->data<<" ";
}

void printTreeLevelWise(TreeNode<int>* root){
    if(root==NULL)
        return;
    queue<TreeNode<int>*> nodes;
    nodes.push(root);
    while(nodes.size()!=0){
        TreeNode<int>* curr_node = nodes.front();
        nodes.pop();
        cout<<curr_node->data<<":";
        for(int i=0;i<curr_node->children.size();i++){
            if(i==curr_node->children.size()-1)
                cout<<curr_node->children[i]->data;
            else
                cout<<curr_node->children[i]->data<<",";
            nodes.push(curr_node->children[i]);
        }
        cout<<endl;
    }
}
void printTree(TreeNode<int>* root){
    if(root==NULL)
        return;
    cout<<root->data<<" : ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<", ";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}
int main(){
    TreeNode<int>* root = takeInputLevelWise();
    /*printTreeLevelWise(root);
    cout<<numNodes(root)<<endl;
    cout<<sumOfNodes(root)<<endl;
    cout<<height(root)<<endl;
    cout<<maxDataNode(root)->data<<endl;
    printAtLevelK(root,2);
    cout<<numLeafNodes(root)<<endl;
    */
    //preorder(root);
    postorder(root);

}
