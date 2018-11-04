#include "../IOLib.hpp"

/***
3-d DP.
Could replace the table by using only one line to reduce space requirement.
Time: O(m*n)
Space: O(m*n) -> O(m)
***/
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int len = 0, rows = M.size();
        if(!rows) return len;
        int cols = M[0].size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(4, 0)));
        for(int i = rows - 1; i >= 0; i--){
            for(int j = cols - 1; j >= 0; j--){
                if(!M[i][j]) continue;
                dp[i][j][0] = (j == cols - 1) ? 1 : (dp[i][j+1][0]+1);
                dp[i][j][1] = (i == rows - 1) ? 1 : (dp[i+1][j][1]+1);
                dp[i][j][2] = (i == rows - 1 || j == cols - 1) ? 1 : (dp[i+1][j+1][2]+1);
                dp[i][j][3] = (i == rows - 1 || j == 0) ? 1 : (dp[i+1][j-1][3]+1);
                for(auto num: dp[i][j]) len = max(len, num);
            }
        }
        return len;
    }
};
