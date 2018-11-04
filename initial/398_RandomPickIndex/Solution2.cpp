#include "../IOLib.hpp"
class Solution {
public:
    Solution(vector<int> nums) {
        numbers = nums;
    }
    
    int pick(int target) {
        int res = 0, count = 0;
        for(int i = 0; i < numbers.size(); i++){
            if(numbers[i] == target){
                count++;
                if(rand() % count == 0) res = i;
            }
        }
        return res;
    }
    
private:
    vector<int> numbers;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
