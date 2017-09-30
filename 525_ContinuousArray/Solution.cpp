#include "../IOLib.hpp"

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxlen = 0;
        unordered_map<int, int> dict;
        dict[0] = -1;
        int balance = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1) balance++;
            else balance--;
            if(dict.find(balance) != dict.end()){
                maxlen = max(i - dict[balance], maxlen);
            }
            else{
                dict[balance] = i;
            }
        }
        return maxlen;
    }
};

int main(void){
    vector<int> nums;
    readVector(nums);
    Solution sol;
    cout << sol.findMaxLength(nums) << endl;
    return 0;
}
