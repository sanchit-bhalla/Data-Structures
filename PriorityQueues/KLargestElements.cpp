#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> kLargest(int input[], int n, int k) {
	// Assume 1st k to be maximum. So insert that in minHeap
    priority_queue<int, vector<int>, greater<int>> pq; // Inbuilt minHeap
    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }

    /* Now we compare rest elements with first k elements. If any element is
       greater than min of k elements then we remove that from heap and insert
       new one.
    */
    for(int i=k;i<n;i++){
        if(input[i] > pq.top()){
            pq.pop();
            pq.push(input[i]);
        }
    }

    /* Now our priority queue has k largest elements . When we remove elements
       they are removed in ascending order bcz we using min heap
       and we store them in vector
    */
    vector<int> ans;
    for(int i=0;i<k;i++){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
