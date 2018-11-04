#include "../IOLib.hpp"

struct TrieNode {
    bool end;
    TrieNode* children[26];
    TrieNode(){
        end = false;
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* ptr = root;
        for(auto c: word){
            int idx = c - 'a';
            if(ptr->children[idx] == nullptr)
                ptr->children[idx] = new TrieNode();
            ptr = ptr->children[idx];
        }
        ptr->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* ptr = root;
        for(auto c: word){
            int idx = c - 'a';
            if(ptr->children[idx] == nullptr) return false;
            ptr = ptr->children[idx];
        }
        return ptr->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* ptr = root;
        for(auto c: prefix){
            int idx = c - 'a';
            if(ptr->children[idx] == nullptr) return false;
            ptr = ptr->children[idx];
        }
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
