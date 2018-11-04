#include "../IOLib.hpp"

class Solution {
public:
    Solution(vector<int> nums) {
        for(auto num: nums){
            dict[num]++;
        }
        numbers = vector<int>(nums);
        srand (time(NULL));
    }
    
    int pick(int target) {
        int idx = rand() % dict[target];
        int count = 0;
        for(int i = 0; i < numbers.size(); i++){
            if(numbers[i] == target){
                if(count != idx) count++;
                else return i;
            }
        }
    }
    
private:
    unordered_map<int, int> dict;
    vector<int> numbers;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
