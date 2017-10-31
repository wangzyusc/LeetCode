#include "../IOLib.hpp"

/***
Only need to find one of the peak elements if multiple candidates exist.
Binary search.
Time: O(log(n))
Space: O(1)
***/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while(i < j){
            int mid = i + (j - i) / 2;
            if((mid == 0 || nums[mid] > nums[mid-1]) &&
               (mid == nums.size()-1 || nums[mid] > nums[mid+1]))
                return mid;
            else if(mid == 0 || nums[mid] > nums[mid-1])
                i = mid + 1;
            else j = mid;
        }
        return i;
    }
};
