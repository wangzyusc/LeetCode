#include "../IOLib.hpp"

/***
Brute-force: O(n^3)
Binary-search: O(n^2 * log(n))
Two-pointers: O(n^2)
***/

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = nums.size() - 1; i >= 0; i--){
            int subtarget = target - nums[i];
            int left = 0, right = i - 1;
            while(left < right){
                if(nums[left] + nums[right] < subtarget){
                    res += (right - left);
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return res;
    }
};
