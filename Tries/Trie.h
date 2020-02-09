#include"TrieNode.h"
#include<string>

class Trie{
    TrieNode *root;
public:
    Trie(){
        root = new TrieNode('\0');
    }
private:
    // Helper function
    void insertWord(TrieNode* root, string word){
        //Base Case
        if(word.size()==0){
            root->isTerminal = true;
            return;
        }

        // Small calculation
        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertWord(child,word.substr(1));
    }
    bool search(TrieNode* root, string word){
        // Base case
        if(word.size()==0){
            if(root->isTerminal ==true)
                return true;
            return false;
        }
        //Small calculation
        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
            // Recursive call
            return search(child,word.substr(1));
        }else{
            return false;
        }
    }

    void removeWord(TrieNode* root, string word){
        // Base case
        if(word.size()==0){
            root->isTerminal = false;
            return;
        }

        // Small Calculation
        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            // word not found
            return;
        }
        removeWord(child, word.substr(1));

        // Remove child Node if useless
        if(child->isTerminal == false){
            for(int i=0;i<26;i++){
                if(child->children[i]!=NULL){
                    // Not useless
                    return;
                }
            }
            // Useless bcz. all indexes of children array is NULL & child->isTerminal is false
            delete child;
            root->children[index] = NULL; // bcz child is removed
        }
    }
public:
    // For user
    void insertWord(string word){
        insertWord(root,word);
    }

    bool search(string word){
        return search(root,word);
    }
    void insert_in_suffix_Trie(string word){
        // This fun. insert word as well as its all suffixes in trie also
        for(int i=0;i<word.size();i++){
            insertWord(word.substr(i));
        }
    }
    void removeWord(string word){
        removeWord(root, word);
    }
    bool patternMatching(vector<string> vect, string pattern) {
        // Insert all words with their suffixes in trie
        for(int i=0;i<vect.size();i++){
            insert_in_suffix_Trie(vect[i]);
        }

        // Search pattern
        return search(root,pattern);
	}
};
