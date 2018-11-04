#include "../IOLib.hpp"

/***
As long as there's a continuous increase, buy from bottom
and sell from top. Greedy.
Time: O(n)
Space: O(1)
***/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int res = 0;
        for(int i = 0; i < prices.size() - 1; i++){
            if(prices[i + 1] > prices[i])
                res += prices[i+1] - prices[i];
        }
        return res;
    }
};
