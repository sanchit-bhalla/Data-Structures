#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> kSmallest(int *input, int n, int k) {
	// Assume 1st k to be minimum. So insert that in maxHeap
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }

    /* Now we compare rest elements with first k elements. If any element is
       samller than max of k elements then we remove that from heap and insert
       new one.
    */
    for(int i=k;i<n;i++){
        if(input[i] < pq.top()){
            pq.pop();
            pq.push(input[i]);
        }
    }

    /* Now our priority queue has k smallest elements . When we remove elements
       they are removed in descending order bcz we using max heap
       and we store them in vector
    */
    vector<int> ans;
    for(int i=0;i<k;i++){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
