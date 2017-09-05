#include "../IOLib.hpp"

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if(nums.size() == 0) return 0;
        unordered_map<int, int> sums;
        int acc_sum = 0, max_len = 0;
        for(int i = 0; i < nums.size(); i++){
            acc_sum += nums[i];
            if(acc_sum == k) max_len = i + 1;
            else if(sums.find(acc_sum - k) != sums.end())
                max_len = max(max_len, i - sums[acc_sum - k]);
            if(sums.find(acc_sum) == sums.end())
                sums[acc_sum] = i;
        }
        return max_len;
    }
};

int main(void){
    cout << "Input Array: ";
    vector<int> nums;
    readVector(nums);
    cout << "Target sum: ";
    int k = readInt();
    Solution solution;
    int len = solution.maxSubArrayLen(nums, k);
    cout << "Maximum length is " << len << endl;
    return 0;
}
