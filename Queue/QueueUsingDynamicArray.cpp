#include<iostream>
using namespace std;

template <typename T>
class QueueUsingDynamicArray{
    T *data;
    int size;
    int capacity;
    int nextIndex;
    int firstIndex;
public:
    QueueUsingDynamicArray(){
        data = new T[5]; //initially
        firstIndex = -1;
        nextIndex = 0;
        size = 0;
        capacity = 5; // Initially
    }

    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    void enqueue(T element){
        if(size == capacity){
            T *newData = new T[capacity*2];
            int j=0;
            for(int i=firstIndex;i<capacity;i++){
                newData[j] = data[i];
                j++;
            }
            for(int i=0;i<firstIndex;i++){
                newData[j] = data[i];
                j++;
            }
            delete [] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex+1)%capacity;
        if(firstIndex== -1)
            firstIndex = 0;
        size++;
    }
    T front(){
        if(isEmpty()){
            cout<<"Queue is empty \n";
            return 0;
        }
        return data[firstIndex];
    }
    T dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty \n";
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex+1)%capacity;
        size--;
        if(size==0){
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
};
