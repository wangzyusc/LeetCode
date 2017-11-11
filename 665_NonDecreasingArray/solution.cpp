#include "../IOLib.hpp"

/***
Time: O(n)
Space: O(1)
If nums[i-1] > nums[i], there're 2 cases:
  2           2
    3   or  1
1               3
Adjust the values to make it motonically nondecreasing.
***/
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool modified = false;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] > nums[i]){
                if(modified) return false;
                modified = true;
                if(i < 2 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];
                else
                    nums[i] = nums[i-1];
            }
        }
        return true;
    }
};
