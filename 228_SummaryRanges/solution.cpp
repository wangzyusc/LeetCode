#include "../IOLib.hpp"

/***
Time: O(n)
Space: O(1)
***/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.empty()) return res;
        int begin = nums[0], prev = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == prev + 1){
                prev = nums[i];
            }
            else{
                if(begin == prev)
                    res.push_back(to_string(begin));
                else
                    res.push_back(to_string(begin) + "->" + to_string(prev));
                begin = prev = nums[i];
            }
        }
        if(begin == prev)
            res.push_back(to_string(begin));
        else
            res.push_back(to_string(begin) + "->" + to_string(prev));
        return res;
    }
};

/***
Two-pointer method could be more concise.
Time: O(n)
Space: O(1)
***/
class Solution1 {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.empty()) return res;
        for(int i = 0, j = 0; j < nums.size(); j++){
            i = j;
            while(j < (nums.size() - 1) && (nums[j] + 1 == nums[j+1]))
                j++;
            if(i == j)
                res.push_back(to_string(nums[i]));
            else
                res.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
        }
        return res;
    }
};

int main(void){
    vector<int> nums = readVector<int>();
    Solution1 sol;
    vector<string> res = sol.summaryRanges(nums);
    printVector(res);
    return 0;
}
