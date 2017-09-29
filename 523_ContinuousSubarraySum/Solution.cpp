#include "../IOLib.hpp"

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> rmds;
        int sum = 0;
        rmds[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int rmd = (k == 0) ? sum : (sum % k);
            if(rmds.find(rmd) != rmds.end()){
                if(rmds[rmd] < i-1) return true;
                else continue;
            }
            rmds[rmd] = i;
        }
        return false;
    }
};

int main(void){
    vector<int> nums;
    readVector(nums);
    int k = readInt();
    Solution sol;
    bool res = sol.checkSubarraySum(nums, k);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
