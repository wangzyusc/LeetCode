#include "../IOLib.hpp"
/***
This is solution using Trie and DFS recursion, but TLE.
***/
struct TrieNode {
    vector<TrieNode*> child;
    bool isword;
    TrieNode(){
        child = vector<TrieNode*>(26, nullptr);
        isword = false;
    }
};
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        TrieNode* root = new TrieNode;
        constructTrie(wordDict, root);
        backtrack(res, s, root, 0, "");
        return res;
    }
    void constructTrie(vector<string>& wordDict, TrieNode* root){
        TrieNode* ptr = root;
        for(string& s: wordDict){
            ptr = root;
            for(char c: s){
                if(ptr->child[c-'a'] == nullptr)
                    ptr->child[c-'a'] = new TrieNode;
                ptr = ptr->child[c-'a'];
            }
            ptr->isword = true;
        }
    }
    void backtrack(vector<string>& res, string& s, TrieNode* root, int pos, string prev){
        if(pos == s.size()){
            res.push_back(prev); return;
        }
        int i = pos;
        TrieNode* ptr = root;
        while(i < s.size() && ptr){
            ptr = ptr->child[s[i]-'a'];
            if(ptr && ptr->isword){
                backtrack(res, s, root, i + 1, prev + (prev.size() ? " " : "") + s.substr(pos, i-pos+1));
            }
            i++;
        }
    }
};

/***
Use a hashset as dictionary, and memoize previous results.
***/
class Solution {
    unordered_map<string, vector<string>> memo;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        return backtrack(s, words);
    }
    vector<string> backtrack(string s, unordered_set<string>& words){
        if(memo.find(s) != memo.end()) return memo[s];
        vector<string> result;
        if(words.count(s)) result.push_back(s);
        for(int i = 1; i < s.size(); i++){
            if(words.count(s.substr(0, i))){
                auto temp = combine(s.substr(0, i), backtrack(s.substr(i), words));
                result.insert(result.end(), temp.begin(), temp.end());
            }
        }
        memo[s] = result;
        return result;
    }
    vector<string> combine(string s, vector<string> prev){
        for(int i = 0; i < prev.size(); i++){
            if(prev[i].empty()) prev[i] = s;
            else prev[i] = s + " " + prev[i];
        }
        return prev;
    }
};

int main(void){
    string s = readString();
    vector<string> wordDict = readVector<string>();
    Solution sol;
    vector<string> res = sol.wordBreak(s, wordDict);
    printVector(res);
    return 0;
}
