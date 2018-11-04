#include "../IOLib.hpp"

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int len = 1, maxlen = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                len++;
                maxlen = max(maxlen, len);
            }
            else len = 1;
        }
        return maxlen;
    }
};

int main(void){
    vector<int> nums;
    readVector(nums);
    Solution sol;
    cout << "res = " << sol.findLengthOfLCIS(nums) << endl;
    return 0;
}
