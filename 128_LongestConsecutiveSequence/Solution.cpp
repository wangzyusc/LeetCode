#include "../IOLib.hpp"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> seq;
        for(auto num : nums)
            seq.insert(num);
        int last = *(seq.begin()) - 1;
        int count = 0, longest = 0;
        cout << "In set:" << endl << "[";
        for(auto it = seq.begin(); it != seq.end(); it++){
            cout << *it << " ";
            if(*it == last + 1){
                count++;
                if(count > longest) longest = count;
            }
            else count = 1;
            last = *it;
        }
        cout << "]" << endl;
        return longest;
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
