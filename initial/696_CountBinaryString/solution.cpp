#include "../IOLib.hpp"

class Solution {
public:
    int countBinarySubstrings(string s) {
        if(s.empty()) return 0;
        int res = 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        //dp[i][j] = the balance of 0 and 1s between [i ... j]
        dp[0][0] = (s[0] == '1') ? 1 : -1;
        for(int i = 0; i < s.size() - 1; i++){
            if(i > 0) dp[i][i] = (s[i-1] == '1') ? (dp[i-1][i] - 1) : (dp[i-1][i] + 1);
            for(int j = i + 1; j < s.size(); j++){
                dp[i][j] = (s[j] == '1') ? (dp[i][j-1] + 1) : (dp[i][j-1] - 1);
                if((j - i % 2) && dp[i][j] == 0){
                    int len = (j - i + 1) / 2;
                    char first = s[i];
                    char second = (first == '1') ? '0' : '1';
                    int k;
                    for(k = i; k <= j; k++){
                        if(k < i + len){
                            if(s[k] != first) break;
                        }
                        else{
                            if(s[k] != second) break;
                        }
                    }
                    if(k > j) res++;
                }
            }
        }
printMatrix(dp);
        return res;
    }
};

int main(void){
    string s = readString();
    Solution sol;
    int res = sol.countBinarySubstrings(s);
    cout << "res = " << res << endl;
    return 0;
}
