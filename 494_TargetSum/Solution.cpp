#include "../IOLib.hpp"

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0) return 0;
        return finder(nums, 0, S);
    }
    int finder(vector<int>& nums, int pos, int S){
        if(pos == nums.size()){
            return (0 == S) ? 1 : 0;
        }
        return finder(nums, pos + 1, S - nums[pos]) +
            finder(nums, pos + 1, S + nums[pos]);
    }
};

int main(void){
    vector<int> nums;
    readVector(nums);
    int s = readInt();
    Solution solution;
    cout << "Result is " << solution.findTargetSumWays(nums, s) << endl;
    return 0;
}
