#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> map;
    int size = nums.size();
    for(int i = 0; i < size; i++){
      if(++map[nums[i]] > size/2)
	return nums[i];
    }
  }
};

int main(void){
  vector<int> nums;
  readVector(nums);
  Solution solution;
  int major = solution.majorityElement(nums);
  cout << "Majority element is " << major << endl;
  return 0;
}
