#include<iostream>
using namespace std;

template <typename T>
class QueueUsingArray{
    T *data;
    int size;
    int capacity;
    int nextIndex;
    int firstIndex;
public:
    QueueUsingArray(int s){
        data = new T[s];
        firstIndex = -1;
        nextIndex = 0;
        size = 0;
        capacity = s;
    }

    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    void enqueue(T element){
        if(size == capacity){
            cout<<"Queue full!\n";
            return ;
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
