#include "../IOLib.hpp"

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0;
        rows = matrix.size();
        cols = (rows)?matrix[0].size():0;
        if(!rows || !cols) return 0;
        vector<vector<int>> memo(rows, vector<int>(cols, 0));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(memo[i][j]) continue;
                res = max(res, dfs(matrix, memo, i, j));
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& memo, int i, int j){
        if(memo[i][j]) return memo[i][j];
        for(auto d: directions){
            int y = i + d.first, x = j + d.second;
            if(y >= 0 && y < rows && x >= 0 && x < cols && matrix[y][x] > matrix[i][j]){
                memo[i][j] = max(memo[i][j], dfs(matrix, memo, y, x));
            }
        }
        return ++memo[i][j];
    }
    vector<pair<int,int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
    int rows;
    int cols;
};

int main(void){
    auto matrix = readMatrix();
    Solution sol;
    int res = sol.longestIncreasingPath(matrix);
    cout << "res = " << res << endl;
    return 0;
}
