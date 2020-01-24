#include<vector>
#include<climits>

class MaxPriorityQueue{
    vector<int> pq;
public:
    MaxPriorityQueue(){
    }
    int getSize(){
        return pq.size();
    }
    bool isEmpty(){
        return pq.size() == 0;
    }
    int getMax(){
        if(isEmpty())
            return INT_MIN;
        return pq[0];
    }
    void insert(int element){
        pq.push_back(element);
        int childIndex = pq.size()-1;
        while(childIndex > 0){
            int parentIndex = (childIndex -1)/2;
            if(pq[childIndex] > pq[parentIndex]){
                // Swap elements at childIndex and parentIndex
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else{
                /* It means our heap now satisfy heap order property */
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMax(){
        if(isEmpty())
            return INT_MIN;
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();

        // Down-Heapify
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while(leftChildIndex < pq.size()){
            int maxIndex = parentIndex;
            /* Find maxIndex */
            if(pq[leftChildIndex] > pq[maxIndex])
                maxIndex = leftChildIndex;
            if(rightChildIndex < pq.size() && pq[rightChildIndex] > pq[maxIndex])
                maxIndex = rightChildIndex;

            if(maxIndex == parentIndex)
                break;
            //Swap
            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = maxIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
        return ans;
    }
};
