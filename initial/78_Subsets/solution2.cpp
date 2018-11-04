#include "../IOLib.hpp"

/* Iterative version */
/* Time: O(n^2), Space: O(n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back({});
        for(auto n: nums){
            int len = result.size();
            for(int i = 0; i < len; i++){
                auto temp = result[i];
                temp.push_back(n);
                result.push_back(temp);
            }
        }
        return result;
    }
};

/* Recursive version */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back({});
        subsets(result, nums, nums.size() - 1);
        return result;
    }
    void subsets(vector<vector<int>>& result, vector<int>& nums, int pos){
        if(pos > 0) subsets(result, nums, pos - 1);
        int len = result.size();
        for(int i = 0; i < len; i++){
            auto temp = result[i];
            temp.push_back(nums[pos]);
            result.push_back(temp);
        }
    }
};
