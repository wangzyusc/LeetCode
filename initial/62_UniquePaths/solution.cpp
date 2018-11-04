#include "../IOLib.hpp"

/***
Could save the 2D-array to a 1D-array. So to reduce space complexity.
***/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
            dp[0][i] = 1;
        for(int i = 0; i < m; i++)
            dp[i][0] = 1;
        for(int row = 1; row < m; row++){
            for(int col = 1; col < n; col++)
                dp[row][col] = dp[row][col-1] + dp[row-1][col];
        }
        return dp[m-1][n-1];
    }
};
