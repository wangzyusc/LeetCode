#include "../IOLib.hpp"

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0, start = 0, end = 0;
        int minlen = nums.size() + 1;
        while(end < nums.size()){
            sum += nums[end];
            if(sum >= s){
                while(sum - nums[start] >= s){
                    sum -= nums[start];
                    start++;
                }
                minlen = min(minlen, end - start + 1);
            }
            end++;
        }
        return (minlen == nums.size() + 1) ? 0 : minlen;
    }
};

int main(void){
    vector<int> nums;
    readVector(nums);
    int sum = readInt();
    Solution sol;
    int res = sol.minSubArrayLen(sum, nums);
    cout << "res = " << res << endl;
    return 0;
}
