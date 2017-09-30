#include "../IOLib.hpp"

/*
 * Time complexity: O(n2)
 * Space complexity: O(n)
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> length(nums.size(), 1);
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            int mlen = 0;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    mlen = max(mlen, length[j]);
                }
            }
            length[i] = mlen + 1;
            res = max(res, length[i]);
        }
        return res;
    }
};

int main(void){
    vector<int> nums;
    readVector(nums);
    Solution sol;
    cout << "res = " << sol.lengthOfLIS(nums) << endl;
    return 0;
}
