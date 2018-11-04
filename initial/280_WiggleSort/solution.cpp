#include "../IOLib.hpp"

/**
Solution #1. Sort the array first, then swap the elements pairwisely from the second one.
Time: O(nlog(n))
Space: O(1)
**/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i + 1 < nums.size(); i+=2){
            swap(nums[i], nums[i+1]);
        }
    }
};

/**
Solution #2. Do the swap in only one pass.
Time: O(n)
Space: O(1)
Observe that all sorts are swap values appropriately.
**/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.empty()) return;
        for(int i = 0; i < nums.size() - 1; i++){
            if((i % 2 == 0) == (nums[i] > nums[i+1]))
                swap(nums[i], nums[i+1]);
        }
    }
};
