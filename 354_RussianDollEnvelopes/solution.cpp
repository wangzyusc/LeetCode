#include "../IOLib.hpp"

/**
Brute force + DP.
Time: O(n^2)
Space: O(n)
**/

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.empty()) return 0;
        int res = 1;
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(envelopes.size(), 1);
        for(int i = 1; i < envelopes.size(); i++){
            for(int j = 0; j < i; j++){
                if(envelopes[j].first >= envelopes[i].first) break;
                if(envelopes[j].second < envelopes[i].second){
                    dp[i] = max(dp[i], dp[j] + 1);
                    res = max(res, dp[i]);
                }
            }
        }
        return res;
    }
};

/**
Optimized: binary search + DP. Very similar to LIS.
Time: O(nlog(n))
Space: O(n)
**/
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int>& a, pair<int, int>& b){if(a.first != b.first) return a.first < b.first; else return b.second < a.second;});
        vector<int> dp;
        for(auto p: envelopes){
            int val = p.second;
            auto it = lower_bound(dp.begin(), dp.end(), val);
            if(it == dp.end())
                dp.push_back(val);
            else
                *it = val; 
        }
        return dp.size();
    }
};
