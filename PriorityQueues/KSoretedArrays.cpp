#include<iostream>
#include<queue>
using namespace std;

/* We have to sort array in descending order so we are using max heap
    and inbuilt priority queue uses max heap */
void KSortedArray(int input[], int n, int k){
    priority_queue<int> pq;

    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }

    int j=0;
    for(int i=k;i<n;i++){
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }

    while(!pq.empty()){
        input[j] = pq.top();
        pq.pop();
        j++;
    }
}
int main(){
    int input[] = {10,12,6,7,9};
    KSortedArray(input,5,3);
    for(int i=0;i<5;i++){
        cout<<input[i]<<" ";
    }
}
