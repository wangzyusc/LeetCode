#include "../IOLib.hpp"

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> height(cols, 0), left(cols, 0), right(cols, cols);
        int res = 0;
        for(int i = 0; i < rows; i++){
            int cur_left = 0;
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == '1'){
                    height[j]++;
                    left[j] = max(cur_left, left[j]);
                }
                else{
                    height[j] = 0;
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }
            int cur_right = cols;
            for(int j = cols-1; j >= 0; j--){
                if(matrix[i][j] == '1'){
                    right[j] = min(right[j], cur_right);
                }
                else{
                    right[j] = cols;
                    cur_right = j;
                }
            }
            for(int j = 0; j < cols; j++){
                res = max(res, height[j] * (right[j] - left[j]));
            }
        }
        return res;
    }
};
