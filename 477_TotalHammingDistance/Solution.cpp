#include "../IOLib.hpp"

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int sum = 0, size = nums.size();
        for(int digit = 0; digit < 32; digit++){
            int odd = 0;
            int zeros = 0;
            for(int i = 0; i < nums.size(); i++){
                odd += (nums[i] & 1);
                nums[i] >>= 1;
                if(nums[i] == 0) zeros++;
            }
            sum += (size - odd) * odd;
            if(zeros == size) break;
        }
        return sum;
    }
};

int main(void){
    vector<int> nums;
    readVector(nums);
    Solution sol;
    cout << "res = " << sol.totalHammingDistance(nums) << endl;
    return 0;
}
