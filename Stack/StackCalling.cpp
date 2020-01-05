#include<iostream>
#include"StackUsingDynamicArrays.cpp"
#include"StackUsingTemplates.cpp"
#include"StackUsingLinkedList.cpp"
using namespace std;

int main(){
/*
    StackUsingArray s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(50);
    s.push(50);

    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    //cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
*/
    /*
    Stack_Template_and_Array<char> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    s.push(105);
    s.push(106);

    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
    */
    Stack<int> s;
    cout<<s.isEmpty()<<endl;
    cout<<s.getSize()<<endl;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(105);
    s.push(106);

    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.getSize()<<endl;
    cout<<s.isEmpty()<<endl;
}
