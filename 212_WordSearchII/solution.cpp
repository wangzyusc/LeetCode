#include "../IOLib.hpp"

/***
DFS.
Time: O(mn + #words)
Space: O(mn + #words)
***/

class Solution {
private:
    class Node{
    public:
        vector<Node*> next;
        bool isword;
        string str;
        Node(){
            next = vector<Node*>(26, nullptr);
            isword = false;
            str = "";
        }
    };
    int rows;
    int cols;
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> res;
        rows = board.size();
        cols = rows>0?board[0].size():0;
        Node* root = new Node;
        constructTrie(root, words);
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                dfs(board, visited, root->next[board[i][j]-'a'], res, i, j);
            }
        }
        return vector<string>(res.begin(), res.end());
    }
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited,
             Node* root, unordered_set<string>& res, int y, int x){
        if(!root) return;
        visited[y][x] = true;
        if(root->isword){
            res.insert(root->str);
        }
        for(int i = 0; i < 4; i++){
            int ny = y + dir[i][0], nx = x + dir[i][1];
            if(ny >= 0 && ny < rows && nx >= 0 && nx < cols && !visited[ny][nx] && root->next[board[ny][nx]-'a'])
                dfs(board, visited, root->next[board[ny][nx]-'a'], res, ny, nx);
        }
        visited[y][x] = false;
    }
    void constructTrie(Node* root, vector<string>& words){
        for(string& s: words){
            Node* cur = root;
            for(char c: s){
                int num = c - 'a';
                if(cur->next[num] == nullptr)
                    cur->next[num] = new Node;
                cur = cur->next[num];
            }
            cur->isword = true;
            cur->str = s;
        }
    }
};
