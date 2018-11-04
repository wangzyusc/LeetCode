#include "../../IOLib.hpp"

/**
 * This version ignores previous sum if it's negative, time complexity O(n)
 */
class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        long sum = 0, res = nums[0];
        for(auto n: nums){
            sum += n;
            if(sum > res) res = sum;
            if(sum < 0) sum = 0;
        }
        return res;
    }
};

/**
 * This version is using divide and conquer algorithm, time complexity O(nlog(n)).
 * Implement this only to practice recursive & divide and conquer.
 */
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubHelper(nums, 0, nums.size() - 1);
    }
    long maxSubHelper(vector<int>& nums, int left, int right){
        if(left == right) return nums[left];
        int mid = left + (right - left) / 2;
        auto left_res = maxSubHelper(nums, left, mid),
             right_res = maxSubHelper(nums, mid + 1, right),
             cross_res = crossSubHelper(nums, left, right, mid);
        return max(left_res, max(right_res, cross_res));
    }
    long crossSubHelper(vector<int>& nums, int left, int right, int mid){
        if(left == right) return nums[left];
        long left_res = nums[mid], right_res = nums[mid+1];
        long left_sum = 0, right_sum = 0;
        for(int i = mid; i >= left; i--){
            left_sum += nums[i];
            if(left_sum > left_res) left_res = left_sum;
        }
        for(int i = mid + 1; i <= right; i++){
            right_sum += nums[i];
            if(right_sum > right_res) right_res = right_sum;
        }
        return left_res + right_res;
    }
};
