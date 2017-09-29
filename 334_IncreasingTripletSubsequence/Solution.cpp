#include "../IOLib.hpp"

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
        int min1 = nums[0], min2 = INT_MAX;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= min1){
                min1 = nums[i];
            }
            else if(nums[i] <= min2){
                min2 = nums[i];
            }
            else{
                return true;
            }
        }
        return false;
    }
};

int main(void){
    vector<int> vec;
    readVector(vec);
    Solution sol;
    bool res = sol.increasingTriplet(vec);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
