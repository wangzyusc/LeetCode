#include "../IOLib.hpp"

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> dp(cols + 1, 0);
        int res = 0, prev = 0;
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= cols; j++){
                int temp = dp[j];
                if(matrix[i-1][j-1] == '1'){
                    dp[j] = min(min(temp, dp[j-1]), prev) + 1;
                    res = max(res, dp[j]);
                }
                else dp[j] = 0;
                prev = temp;
            }
        }
        return res * res;
    }
};

int main(void){
    return 0;
}
