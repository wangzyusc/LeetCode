#include "../IOLib.hpp"

/**
Use Trie to accelarate search. And save all the string that matches this node to save DFS search time.
**/

class node{
public:
    vector<node*> child;
    vector<string> strs;
    node(){
        child = vector<node*>(26, NULL);
    }
};
class Solution {
public:
    node* root;
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> res;
        if(words.empty()) return res;
        int len = words[0].length();
        root = new node;
        buildtrie(words);
        vector<string> square;
        for(int i = 0; i < words.size(); i++){//use as first
            square.push_back(words[i]);
            helper(res, words, square, len);
            square.pop_back();
        }
        return res;
    }
    void buildtrie(vector<string>& words){
        for(int i = 0; i < words.size(); i++){
            node* cur = root;
            for(auto c: words[i]){
                cur->strs.push_back(words[i]);
                int val = c - 'a';
                if(cur->child[val] == NULL){
                    cur->child[val] = new node;
                }
                cur = cur->child[val];
            }
            cur->strs.push_back(words[i]);
        }
    }
    void helper(vector<vector<string>>& res, vector<string>& words, vector<string>& square, int len){
        if(square.size() == len){
            res.push_back(square);
            return;
        }
        int pre = square.size();
        node* cur = root;
        for(int i = 0; i < pre; i++){
            cur = cur->child[square[i][pre] - 'a'];
            if(cur == NULL) return;
        }
        //if(pre < len && cur->num == 0) return;
        /*vector<string> cand;
        {
            queue<node*> q;
            q.push(cur);
            while(!q.empty()){
                node* head = q.front();
                q.pop();
                if(head->isword){
                    cand.push_back(words[head->num]);
                    continue;
                }
                for(auto p: head->child){
                    if(p) q.push(p);
                }
            }
        }*/
        for(auto w: cur->strs){
            square.push_back(w);
            helper(res, words, square, len);
            square.pop_back();
        }
    }
};

int main(void){
    vector<string> dict = readVector<string>();
    Solution sol;
    auto res = sol.wordSquares(dict);
    for(auto square: res){
        printVector(square);
    }
    return 0;
}
