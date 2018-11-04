#include "../IOLib.hpp"

/**
Dynamic Programming.
Time: O(mn)
Space: O(n)
**/

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int result = 0;
        int rows = grid.size();
        int cols = rows ? grid[0].size() : 0;
        int numRow = 0;
        vector<int> numCols(cols, 0);
        //memset(numCols, sizeof numCols, 0);
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(i == 0 || grid[i-1][j] == 'W'){
                    numCols[j] = 0;
                    for(int k = i; k < rows && grid[k][j] != 'W'; k++){
                        numCols[j] += (grid[k][j] == 'E');
                    }
                }
                if(j == 0 || grid[i][j-1] == 'W'){
                    numRow = 0;
                    for(int k = j; k < cols && grid[i][k] != 'W'; k++){
                        numRow += (grid[i][k] == 'E');
                    }
                }
                if(grid[i][j] == '0')
                    result = max(result, numRow + numCols[j]);
            }
        }
        return result;
    }
};
