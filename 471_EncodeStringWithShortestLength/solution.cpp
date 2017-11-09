#include "../IOLib.hpp"

/***
DP. There's another DP solution in O(n^2)
Time: O(n^3)
Space: O(n^3)
***/
class Solution {
public:
    string encode(string s) {
        int n = s.size();
        vector<vector<string>> dp(n, vector<string>(n, ""));
        for(int step = 1; step <= n; step++){
            for(int i = 0; i + step <= n; i++){
                int j = i + step - 1;
                dp[i][j] = s.substr(i, step);
                for(int k = i; k < j; k++){
                    string sum = dp[i][k] + dp[k+1][j];
                    if(sum.size() < dp[i][j].size())
                        dp[i][j] = sum;
                }
                string alter = collapse(s, i, j, dp);
                if(alter.size() < dp[i][j].size())
                    dp[i][j] = alter;
            }
        }
        return dp[0][n-1];
    }
    string collapse(string& s, int i, int j, vector<vector<string>>& dp){
        string temp = s.substr(i, j - i + 1);
        auto pos = (temp + temp).find(temp, 1);
        if(pos >= temp.size()) return temp;
        return to_string(temp.size() / pos) + "[" + dp[i][i+pos-1] + "]";
    }
};
