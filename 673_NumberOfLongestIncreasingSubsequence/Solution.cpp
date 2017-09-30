#include "../IOLib.hpp"

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> length(nums.size(), 1);
        vector<int> number(nums.size(), 1);
        int g_maxlen = 1, g_count = 0;
        for(int j = 0; j < nums.size(); j++){
            int max = 0, count = 1;
            for(int i = 0; i < j; i++){
                if(nums[i] < nums[j]){
                    if(length[i] > max){
                        max = length[i];
                        count = number[i];
                    }
                    else if(length[i] == max){
                        count += number[i];
                    }
                }
            }
            length[j] = max + 1;
            number[j] = count;
            if(length[j] > g_maxlen){
                g_maxlen = length[j];
                g_count = number[j];
            }
            else if(length[j] == g_maxlen){
                g_count += count;
            }
        }
        printVector(length);
        printVector(number);
        return g_count;
    }
};

int main(void){
    vector<int> nums;
    readVector(nums);
    Solution sol;
    int res = sol.findNumberOfLIS(nums);
    cout << res << endl;
    return 0;
}
