#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  bool canJump(vector<int>& nums) {
    int length = nums.size();
    if(length < 2) return true;
    int max = nums[0], i = 0;
    while(i <= max && max < length-1){
      if(i + nums[i] > max) max = i + nums[i];
      i++;
    }
    if(max >= length-1) return true;
    else return false;
  }
};

int main(void){
    vector<int> data;
    readVector(data);
    Solution solution;
    bool res = solution.canJump(data);
    cout << "The result is " << (res ? "true" : "false") << endl;
    return 0;
}
