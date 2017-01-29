#include "../IOLib.hpp"

using namespace std;

/*
 * With reference to:
 * http://fisherlei.blogspot.com/2012/12/leetcode-next-permutation.html
 */

class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    int length = nums.size();
    if(length < 2) return;
    int partition, change;
    int i;
    for(i = length - 2; i >= 0; i--){
      if(nums[i] < nums[i+1]){
	partition = nums[i];
	break;
      }
    }
    if(i >= 0){
      for(int j = length - 1; j > i; j--){
	if(nums[j] > nums[i]){
	  nums[i] = nums[j];
	  nums[j] = partition;
	  break;
	}
      }
    }
    reverse(nums.begin()+1+i, nums.end());
  }
};

int main(){
    vector<int> vec;
    readVector(vec);
    Solution solution;
    solution.nextPermutation(vec);
    viewVector(vec);
    return 0;
}
