#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int length = nums.size();
    if(length == 0) return 0;
    int start = 0, end = length - 1;
    while(start < end){
      int mid = (start + end)/2;
      if(nums[mid] == target) return mid;
      else if(nums[mid] < target) start = mid + 1;
      else end = mid;
    }
    //start == end
    if(nums[start] >= target) return start;
    //else if(nums[start] < target) 
    return start+1;
  }
};

int main(){
  vector<int> nums;
  readVector(nums);
  int target = readInt();
  Solution solution;
  int result = solution.searchInsert(nums, target);
  cout << "The result is " << result << endl;
  return 0;
}
