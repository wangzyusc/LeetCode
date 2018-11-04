#include "../IOLib.hpp"

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> way(target + 1, 0);
        way[0] = 1;
        for(int i = 1; i < way.size(); i++){
            for(auto num: nums){
                if(num <= i){
                    way[i] += way[i - num];
                }
                else break;
            }
        }
        return way[target];
    }
};

int main(void){
    return 0;
}
