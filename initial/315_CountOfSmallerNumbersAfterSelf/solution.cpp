#include "../IOLib.hpp"

/**
In addition to following methods, could also be done by Binary Search Tree or Merge Sort.
**/

/**
Near Brute force.
Time: O(n^2log(n))
Space: O(n)
**/

class Solution1 {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        if(nums.empty()) return res;
        map<int, int> counts;
        for(int i = nums.size() - 1; i >= 0; i--){
            for(auto it = counts.begin(); it != counts.end() && it->first < nums[i]; it++){
                res[i] += it->second;
            }
            counts[nums[i]]++;
        }
        return res;
    }
};

/**
Binary Indexed Tree.
Time: O(nlog(n))
Space: O(num range)
**/

class Solution2 {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        if(nums.empty()) return res;
        int minval = nums[0], maxval = nums[0];
        for(auto n: nums){
            minval = min(minval, n);
            maxval = max(maxval, n);
        }
        vector<int> bit(maxval - minval + 2, 0);
        maxval -= minval;
        maxval++;
        for(int i = nums.size() - 1; i >= 0; i--){
            int pos = nums[i] - minval + 1;
            int j = pos;
            while(j <= maxval){
                bit[j]++;
                j += (j & -j);
            }
            j = pos - 1;
            while(j > 0){
                res[i] += bit[j];
                j -= (j & -j);
            }
        }
        return res;
    }
};

int main(void){
    vector<int> nums = readVector<int>();
    Solution2 sol;
    vector<int> res = sol.countSmaller(nums);
    printVector(res);
    return 0;
}
