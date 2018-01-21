#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int i = 0, j = 0;
    int size = nums.size();
    for(; i < size; i++){
      if(nums[i] != 0){
	nums[j++] = nums[i];
      }
    }
    for(; j < size; j++){
      nums[j] = 0;
    }
  }
};

/* More concise version */
/* This solution uses Two-pointer method */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.empty()) return;
        int j = 0;
        for(auto &n: nums){
            if(n) swap(n, nums[j++]);
        }
    }
};

int main(void){
  vector<int> nums;
  readVector(nums);
  printVector(nums);
  Solution solution;
  solution.moveZeroes(nums);
  printVector(nums);
  return 0;
}
