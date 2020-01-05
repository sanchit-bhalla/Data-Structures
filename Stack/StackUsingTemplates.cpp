#include<iostream>
using namespace std;

template <typename T>
class Stack_Template_and_Array{
    T *data;
    int nextIndex;
    int capacity;
public:
    Stack_Template_and_Array(){
        data = new T[4];
        nextIndex = 0;
        capacity = 4;
    }

    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        return nextIndex==0;
    }
    void push(T element){
        if(nextIndex==capacity){
            T *newdata = new T[capacity*2];
            for(int i=0;i<capacity;i++)
                newdata[i] = data[i];
            capacity *= 2;
            delete [] data;
            data = newdata;
        }
        data[nextIndex]=element;
        nextIndex++;
    }
    T pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        nextIndex --;
        return data[nextIndex];
    }
    // Returns the top element but do not delete it
    T top(){
        if(isEmpty()){
            cout<<"Stack is empty ";
            return 0;
        }
        return data[nextIndex-1];
    }
};
