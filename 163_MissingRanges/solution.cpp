#include "../IOLib.hpp"

/**
Time: O(n)
Space: O(1)
**/

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        long begin = lower;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == begin){
                begin++;
            }
            else if(nums[i] == begin + 1){
                result.push_back(to_string(begin));
                begin = (long)nums[i] + 1;
            }
            else if(nums[i] > begin + 1){
                result.push_back(to_string(begin) + "->" + to_string(nums[i]-1));
                begin = (long)nums[i] + 1;
            }
        }
        if(begin < upper){
            result.push_back(to_string(begin) + "->" + to_string(upper));
        }
        else if(begin == upper){
            result.push_back(to_string(begin));
        }
        return result;
    }
};
