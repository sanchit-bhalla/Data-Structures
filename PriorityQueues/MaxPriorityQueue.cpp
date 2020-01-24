#include<iostream>
using namespace std;
#include"MaxPriorityQueue.h"

int main(){
    MaxPriorityQueue p;
    p.insert(10);
    p.insert(100);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout<<p.getMax()<<endl;
    cout<<p.getSize()<<endl;

    while(!p.isEmpty()){
        cout<<p.removeMax()<<" ";
    }
    cout<<endl;
}

