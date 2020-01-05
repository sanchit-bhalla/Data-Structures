#include<iostream>
#include<climits>
using namespace std;

class StackUsingArray{
    int *data;
    int capacity;
    int nextIndex;

public:
    StackUsingArray(){
        data = new int[4]; //Assume initially size of array is 4
        capacity = 4; // Assume initially capacity to be
        nextIndex =0;
    }

    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        return nextIndex==0;
    }
    void push(int element){
        if(nextIndex==capacity){
            int *newdata = new int[capacity*2];
            for(int i=0;i<capacity;i++)
                newdata[i] = data[i];
            capacity *= 2;
            delete [] data;
            data = newdata;
        }
        data[nextIndex]=element;
        nextIndex++;
    }
    int pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
        nextIndex --;
        return data[nextIndex];
    }
    // Returns the top element but do not delete it
    int top(){
        if(isEmpty()){
            cout<<"Stack is empty ";
            return INT_MIN;
        }
        return data[nextIndex-1];
    }
};
