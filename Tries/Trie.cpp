#include<iostream>
#include<vector>
using namespace std;
#include"Trie.h"
void reverse(string str){
    cout<<"reverse.str: "<<str<<endl;
        int i=0;
        int j=str.length()-1;
        while(i<j){
            // Swap
            char t = str[i];
            str[i] = str[j];
            str[j] = t;
            i++;
            j--;
        }
    }
int main(){
    string s="abcdef";
    cout<<"main.s: "<<s<<endl;


    reverse(s);
    cout<<s<<endl;
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
