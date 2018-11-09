#include "../../IOLib.hpp"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        for(auto& num: nums){
            if(num != nums[j]){
                nums[++j] = num;
            }
        }
        return min((int)nums.size(), j + 1);
    }
};
