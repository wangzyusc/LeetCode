#include "../IOLib.hpp"

/**
Time: O(n)
Space: O(1)
**/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, count = 0;
        for(auto n: nums){
            if(n == 1){
                count++;
                if(count > res) res = count;
            }
            else count = 0;
        }
        return res;
    }
};
