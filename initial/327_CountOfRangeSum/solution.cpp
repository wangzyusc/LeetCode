#include "../IOLib.hpp"

/***
Based on accumulative sums and perform Merge Sort.
Be careful about the boundary! In merge function, it actually cares for range
[left, right).
Time: O(n*log(n))
Space: O(n)
***/
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.empty()) return 0;
        vector<long> sums(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++){
            sums[i+1] = sums[i] + nums[i];
        }
        return merge(sums, 0, nums.size() + 1, lower, upper);
    }
    int merge(vector<long>& sums, int left, int right, int lower, int upper){//"right" is exclusive
        if(left + 1 >= right) return 0;
        int mid = left + (right - left) / 2;
        int count = merge(sums, left, mid, lower, upper) + merge(sums, mid, right, lower, upper);
        int m = mid, n = mid;
        for(int i = left; i < mid; i++){
            while(m < right && sums[m] - sums[i] < lower) m++;
            while(n < right && sums[n] - sums[i] <= upper) n++;
            count += n - m;
        }
        inplace_merge(sums.begin() + left, sums.begin() + mid, sums.begin() + right);
        return count;
    }
};
