#include<iostream>
using namespace std;
#include"Trie.h"

int main(){
    Trie t;
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");
    cout<<t.search("and")<<endl;
    cout<<t.search("are")<<endl;
    cout<<t.search("dot")<<endl;
    t.removeWord("and");
    cout<<t.search("and")<<endl;
    cout<<t.search("are")<<endl;
    cout<<t.search("dot")<<endl;
}
