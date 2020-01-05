#include<iostream>
#include"Node.cpp"
using namespace std;

Node *reverseLL_Rec(Node *head){
    if(head==NULL || head->next==NULL)
        return head;
    Node *smallAns = reverseLL_Rec(head->next);
    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return smallAns;
}

Node *reverseLL_Iterative(Node *head){
    if(head==NULL || head->next==NULL)
        return head;

    Node *prev = NULL;
    Node *current = head;
    Node *next = current->next;

    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

/* This function takes input from user until -1 is encountered */
Node* takeInput(){
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data!= -1){
        Node *newNode = new Node(data);
        if(head==NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next; // or tail = newNode
        }
        cin>>data;
    }
    return head;
}
Node* insertNode(Node *head, int i, int data){
    Node *newNode = new Node(data);
    int count_=0;
    Node *temp = head;
    if(i==0){
        newNode->next=head;
        head = newNode;
        /*Scope of this head is limited to this function only.
          So we return head so that changes also reflect in main
        */
        return head;
    }
    while(temp!=NULL && count_<i-1){
        temp = temp->next;
        count_++;
    }
    if(temp!=NULL){
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

/* Insert Recursively */
Node* insertNodeRec(Node *head, int i, int data) {
    if(head == NULL && i!=0)
        return head;
    Node *newNode = new Node(data);
    if(i==0){
        newNode->next = head;
        head = newNode;
        return head;
    }else{
        Node *recur_head = insertNodeRec(head->next, i-1, data);
        head->next = recur_head;
        return head;
    }

}

Node* deleteNode(Node *head, int i) {
    Node *temp = head;
    int count_=0;
    if(i==0){
        head = head->next;
        return head;
    }
    while(temp->next!=NULL && count_<i-1){
        temp=temp->next;
        count_++;
    }
    if(temp->next != NULL){
        Node *a=temp->next;
        temp->next = a->next;
        delete a;
    }
    return head;
}

/*  Delete Recursively */
Node* deleteNodeRec(Node *head, int i) {
    if(head == NULL)
        return head;
    if(i==0){
        head = head->next;
        return head;
    }else{
        Node *recur_head = deleteNodeRec(head->next, i-1);
        head->next = recur_head;
        return head;
    }
}

void print(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node *head = takeInput();
    print(head);
    Node *rh = reverseLL_Iterative(head);
    print(rh);
    /*int i,data;
    cin>>i>>data;
    head = insertNodeRec(head, i, data);
    print(head);
    int j;
    cin>>j;
    head = deleteNodeRec(head, j);
    print(head);*/
}
