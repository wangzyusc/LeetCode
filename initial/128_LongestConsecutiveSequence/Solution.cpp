#include "../IOLib.hpp"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> seq;
        for(auto num : nums)
            seq.insert(num);
        int len = 0;
        for(auto num: nums){
            if(seq.find(num) == seq.end()) continue;
            seq.erase(num);
            int prev = num-1, next = num+1;
            while(seq.find(prev) != seq.end()){
                seq.erase(prev);
                prev--;
            }
            while(seq.find(next) != seq.end()){
                seq.erase(next);
                next++;
            }
            len = max(next - prev - 1, len);
        }
        return len;
    }
};

int main(void){
    vector<int> nums;
    readVector(nums);
    Solution solution;
    int res = solution.longestConsecutive(nums);
    cout << res << endl;
    return 0;
}
