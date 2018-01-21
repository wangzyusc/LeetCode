#include "../IOLib.hpp"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int left = 0, right = nums.size() - 1;
        while(nums[left] > nums[right]){
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[right])
                right = mid;
            else if(nums[mid] >= nums[left])
                left = mid + 1;
        }
        int bias = left, len = nums.size(); // left == right
        left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2, index = (mid + bias) % len;
            if(nums[index] == target) return index;
            else if(nums[index] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};

int main(void){
    vector<int> input = readVector<int>();
    Solution sol;
    int target = readInt();
    int res = sol.search(input, target);
    cout << "The index of " << target << " is " << res << endl;
    return 0;
}
