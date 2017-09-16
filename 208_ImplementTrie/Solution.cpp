#include "../IOLib.hpp"

struct TrieNode{
    char c;
    bool end;
    TrieNode* children[26];
    TrieNode(char ch): c(ch) {
        end = false;
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('0');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* ptr = root, *last = nullptr;
        for(auto c: word){
            int idx = c - 'a';
            if(ptr->children[idx] == nullptr)
                ptr->children[idx] = new TrieNode(c);
            ptr = ptr->children[idx];
        }
        ptr->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return search(word, root);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return false;
    }
private:
    bool search(string word, TrieNode* root){
        if(root == nullptr) return false;
        if(word.size() == 0) return root->end;
        string res = word.substr(1);
        if(word[0] == '.'){
            for(int idx = 0; idx < 26; idx++){
                if(search(res, root->children[idx]))
                    return true;
            }
            return false;
        }
        int idx = word[0] - 'a';
        return search(res, root->children[idx]);
    }
    bool startsWith(string word, TrieNode* root){
        if(root == nullptr) return false;
        if(word.size() == 0){
            if(root->end) return true;
            for(int i = 0; i < 26; i++){
                if(root->children[i] != nullptr) return true;
            }
            return false;
        }
        string res = word.substr(1);
        if(word[0] == '.'){
            for(int idx = 0; idx < 26; idx++){
                if(startsWith(res, root->children[idx]))
                    return true;
            }
            return false;
        }
        int idx = word[0] - 'a';
        return startsWith(res, root->children[idx]);
    }
public:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main(void){
    Trie obj;
    obj.insert("abc");
    obj.insert("a");
    //cout << obj.search("abc") << endl;
    //cout << obj.search("a") << endl;
    cout << obj.root->children[0] << endl;
    cout << obj.root->children[0]->c << endl;
    cout << obj.root->children[0]->end << endl;
    cout << obj.root->children[0]->children[1] << endl;
    return 0;
}
