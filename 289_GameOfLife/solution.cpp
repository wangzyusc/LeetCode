#include "../IOLib.hpp"

/***
This is naive solution.
Time: O(m * n)
Space: O(m * n)
There's also in-place solution, put temporary values like 2 and -1 in place to represent its next status.
***/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        if(rows == 0) return;
        int cols = board[0].size();
        vector<vector<int>> count(rows, vector<int>(cols, 0));
        vector<vector<int>> bias{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                for(auto b: bias){
                    int y = i + b[0], x = j + b[1];
                    if(y < 0 || y >= rows || x < 0 || x >= cols) continue;
                    if(board[y][x] == 1) count[i][j]++;
                }
            }
        }
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 1){
                    if(count[i][j] < 2 || count[i][j] > 3) board[i][j] = 0;
                }
                else{
                    if(count[i][j] == 3) board[i][j] = 1;
                }
            }
        }
    }
};
