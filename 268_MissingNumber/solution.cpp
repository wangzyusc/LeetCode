#include "../IOLib.hpp"

/* Use Gauss's formula, another good method is bit manipulation.
 * for(i : {0, 1, ..., n}) result ^= (i ^ nums[i]);
 * Since x XOR x = 0 and 0 ^ x = x, a ^ b ^ c = c ^ b ^ a.
 * Time: O(n), Space: O(1).
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), sum = 0, suppose = (n * (n + 1)) / 2;
        for(auto& num: nums)
            sum += num;
        return suppose - sum;
    }
};
