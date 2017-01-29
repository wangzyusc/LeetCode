#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int length = nums.size();
    if(length < 2) return length;
    int res = 1, last = nums[0];
    for(int i = 1; i < length; i++){
      if(nums[i] != last){
	nums[res] = nums[i];
	res++;
	last = nums[i];
      }
    }
    return res;
  }
};

int main(void){
  vector<int> input;
  readVector(input);
  Solution solution;
  int result = solution.removeDuplicates(input);
  cout << "result length is " << result << endl;
  viewVector(input);
  return 0;
}
