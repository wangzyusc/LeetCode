#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int single = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++){
      single ^= nums[i];
    }
    return single;
  }
};

int main(void){
  vector<int> nums;
  readVector(nums);
  Solution solution;
  cout << "The single number is " << solution.singleNumber(nums) << endl;
  return 0;
}
