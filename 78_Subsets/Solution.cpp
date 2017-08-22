#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> empty;
        result.push_back(empty);
        for(int i = 0; i < nums.size(); i++){
            expand_set(nums, i, result);
        }
        return result;
    }
    void expand_set(vector<int>& nums, int pos, vector<vector<int> >& result){
        int length = result.size();
        for(int i = 0; i < length; i++){
            vector<int> new_item(result[i]);
            new_item.push_back(nums[pos]);
            result.push_back(new_item);
        }
    }
};

int main(void){
    vector<int> nums;
    readVector(nums);
    Solution solution;
    vector<vector<int> > result = solution.subsets(nums);
    printVectorOfVector(result);
    return 0;
}
