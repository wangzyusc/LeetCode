#include "../IOLib.hpp"

const int child_num = 26;

struct Node{
    bool isString = false;
    Node* children[child_num];
    Node(){
        for(int i= 0; i < child_num; i++)
            children[i] = nullptr;
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* ptr = root;
        for(auto c: word){
            if(!ptr->children[c-'a']) ptr->children[c-'a'] = new Node;
            ptr = ptr->children[c-'a'];
        }
        ptr->isString = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, root);
    }
    bool search(string word, Node* root){
        if(word.size() == 0) return root->isString;
        string res = word.substr(1);
        if(word[0] == '.'){
            for(int i = 0; i < child_num; i++){
                if(root->children[i] &&
                   search(res, root->children[i])) return true;
            }
            return false;
        }
        if(root->children[word[0] - 'a'] == nullptr) return false;
        return search(res, root->children[word[0] - 'a']);
    }
private:
    Node* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
