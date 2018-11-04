#include "../IOLib.hpp"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int i = 0;
        while(i < citations.size() &&
              citations[i] >= (i+1))
            i++;
        return i;
    }
};

int main(void){
    vector<int> nums;
    readVector(nums);
    Solution sol;
    cout << "hIndex = " << sol.hIndex(nums) << endl;
    return 0;
}
