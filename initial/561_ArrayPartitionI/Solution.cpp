#include "../IOLib.hpp"

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i < nums.size(); i += 2){
            sum += nums[i];
        }
        return sum;
    }
};

int main(void){
    vector<int> input;
    readVector(input);
    Solution solution;
    cout << "The sum of min elements for each pair in this array is "
         << solution.arrayPairSum(input) << endl;
    return 0;
}
