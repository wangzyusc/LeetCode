#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int size = nums.size();
    vector<int> result(size);
    result[0] = 1;
    for(int i = 1; i < size; i++){
      result[i] = result[i-1] * nums[i-1];
    }
    int product = 1;
    for(int i = size-1; i >= 0; i--){
      result[i] *= product;
      product *= nums[i];
    }
    return result;
  }
};

int main(void){
  vector<int> nums;
  readVector(nums);
  Solution solution;
  vector<int> product = solution.productExceptSelf(nums);
  printVector(product);
  return 0;
}
