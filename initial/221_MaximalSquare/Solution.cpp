#include "../IOLib.hpp"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> size(rows, vector<int>(cols, 0));
        int res = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == '1'){
                    if(i > 0 && j > 0 && size[i-1][j-1] > 0){
                        int pre = size[i-1][j-1];
                        int b;
                        for(b = 1; b <= pre && f; b++){
                            if(matrix[i][j - b] == '0' ||
                               matrix[i - b][j] == '0')
                                break;
                        }
                        size[i][j] = b;
                    }
                    else size[i][j] = 1;
                    res = max(res, size[i][j]);
                }
            }
        }
        return res * res;
    }
};

int main(){
    vector<vector<char> > mat;
    return 0;
}
