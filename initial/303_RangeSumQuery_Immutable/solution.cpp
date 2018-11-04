#include "../IOLib.hpp"

class NumArray {
public:
    NumArray(vector<int> nums) {
        acc = vector<int>(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++){
            acc[i+1] = acc[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return acc[j+1] - acc[i];
    }
private:
    vector<int> acc;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
