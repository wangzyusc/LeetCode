#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int length = nums.size();
        if(length == 0) return 1;
        sort(nums.begin(), nums.end());
        int count = 1;
        for(int i = 0; i < length; i++){
            if(nums[i] <= 0) continue;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            if(nums[i] != count) return count;
            count++;
        }
        return count;
    }
};

int main(){
	vector<int> nums;
	readVector(nums);
	Solution solution;
	int num = solution.firstMissingPositive(nums);
	cout << "First missing positive is " << num << endl;
	return 0;
}