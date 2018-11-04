#include "../IOLib.hpp"

/**
Direction switch.
Time: O(m * n)
Space: O(1)
Could put numbers on each line into a individual vector, and then stitch them together.
**/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int rows = matrix.size();
        int cols = rows > 0 ? matrix[0].size() : 0;
        for(int i = 0; i < rows + cols - 1; i++){
            if(i & 1){
                for(int j = min(i, cols-1); (j >= 0) && (i - j < rows); j--){
                    result.push_back(matrix[i-j][j]);
                }
            }
            else{
                for(int j = min(i, rows-1); (j >= 0) && (i - j < cols); j--){
                    result.push_back(matrix[j][i-j]);
                }
            }
        }
        return result;
    }
};
