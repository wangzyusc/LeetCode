#include "../IOLib.hpp"

/***
Dynamic Programming.
Time: O(n)
Space: O(n)
***/

class Solution {
public:
    int numWays(int n, int k) {
        if(n < 1) return 0;
        vector<int> same(n, 0);
        vector<int> diff(n, 0);
        same[0] = 0;
        diff[0] = k;
        for(int i = 1; i < n; i++){
            same[i] = diff[i-1];
            diff[i] = (same[i-1] + diff[i-1]) * (k - 1);
        }
        return same.back() + diff.back();
    }
};
