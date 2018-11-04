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

/* More concise version */
class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != nums[j])
                swap(nums[i], nums[++j]);
        }
        return j + 1;
    }
};

int main(void){
  vector<int> input;
  readVector(input);
  Solution solution;
  int result = solution.removeDuplicates(input);
  cout << "result length is " << result << endl;
  viewVector(input, result);
  return 0;
}
