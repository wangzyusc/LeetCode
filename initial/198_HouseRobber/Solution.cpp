#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    int a = 0;//take the odd one
    int b = 0;//take the even one
    for(int i = 0; i < nums.size(); i++){
      if(i % 2){
	a = max(b, a + nums[i]);
      }
      else{
	b = max(a, b + nums[i]);
      }
    }
    return max(a, b);
  }
};

int main(void){
  vector<int> nums;
  readVector(nums);
  printVector(nums);
  Solution solution;
  cout << "The max amount money can rob is " << solution.rob(nums) << endl;
  return 0;
}
