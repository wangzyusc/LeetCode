#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    int length = nums.size();
    if(length == 0) return 0;
    int reslen = 0;
    for(int i = 0; i < length; i++){
      if(nums[i] != val){
	nums[reslen] = nums[i];
	reslen++;
      }
    }
    return reslen;
  }
};

int main(){
    int val;
    vector<int> input;
    readVector(input);
    cout << "Input the value to remove: ";
    cin >> val;
    Solution solution;
    int result = solution.removeElement(input, val);
    viewVector(input, result);
    return 0;
}
