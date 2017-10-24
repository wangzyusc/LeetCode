#include "../IOLib.hpp"

/***
Notice order of i,j,y,x when calling functions.
DFS.
Time: O(mn)
Space: O(mn)
***/

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        rows = matrix.size();
        if(rows == 0) return {};
        cols = matrix[0].size();
        vector<vector<int>> pac(rows, vector<int>(cols, 0));
        vector<vector<int>> atl(rows, vector<int>(cols, 0));
        for(int i = 0; i < cols; i++){
            pac[0][i] = 1;
            atl[rows-1][i] = 1;
        }
        for(int j = 0; j < rows; j++){
            pac[j][0] = 1;
            atl[j][cols-1] = 1;
        }
        for(int i = 0; i < cols; i++){
            dfs(matrix, pac, 0, i);
            dfs(matrix, atl, rows - 1, i);
        }
        for(int j = 0; j < rows; j++){
            dfs(matrix, pac, j, 0);
            dfs(matrix, atl, j, cols - 1);
        }
        vector<pair<int, int>> res;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(pac[i][j] && atl[i][j])
                    res.push_back(make_pair(i, j));
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& status, int i, int j){
        //if(status[i][j]) return;
        status[i][j] = 1;
        for(auto dir: directions){
            int y = i + dir[0], x = j + dir[1];
            if(x >= 0 && x < cols && y >= 0 && y < rows &&
               matrix[y][x] >= matrix[i][j] && status[y][x] == 0)
                dfs(matrix, status, y, x);
        }
    }
    vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
    int rows;
    int cols;
};
