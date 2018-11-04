#include "../IOLib.hpp"

/***
Could use XOR in O(n) time.
But use pair index to do binary search is O(log(n)).
**/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //use pair index
        int left = 0, right = nums.size() / 2;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid*2] == nums[mid*2+1]){
                left = mid + 1;
            }
            else right = mid;
        }
        return nums[left*2];
    }
};
