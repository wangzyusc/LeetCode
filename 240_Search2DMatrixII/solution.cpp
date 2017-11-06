#include "../IOLib.hpp"

/***
Important trick!
Double-dimension sorted matrix, start from a corner, and move left or
downward according to relative quantity. Reminds me of the "Find left-most 1"
in the previous interview.
Time: O(m + n)
Space: O(1)
***/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = rows>0?matrix[0].size():0;
        if(rows == 0 || cols == 0) return false;
        int i = 0, j = cols - 1;
        while(i < rows && j >= 0){
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};
