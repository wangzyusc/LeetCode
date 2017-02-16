#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int length = nums.size();
    vector<int> res;
    res.push_back(-1); res.push_back(-1);
    int start = 0, end = length - 1;
    if(length == 0 || nums[start] > target || nums[end] < target)
      return res;
    if(nums[start] == nums[end]){
      res[0] = start;
      res[1] = end;
      return res;
    }
    int pos = -1;
    while(start < end){
      int mid = (start + end) / 2;
      if(nums[mid] < target){
	start = mid + 1;
      }
      if(nums[mid] >= target){
	end = mid;
      }
    }
    //start == end
    if(nums[start] == target) res[0] = start;
    else return res;
    //start == res[0]
    end = length - 1;
    while(start < end){
      int mid = (start + end) / 2;
      if(nums[mid] <= target){
	start = mid + 1;
      }
      if(nums[mid] > target){
	end = mid;
      }
    }
    //start == end
    if(nums[end] == target) res[1] = end;
    else if(nums[end-1] == target) res[1] = end-1;
    return res;
  }
};

int main(){
  vector<int> input;
  readVector(input);
  int target = readInt();
  Solution solution;
  vector<int> result = solution.searchRange(input, target);
  cout << "The result is ";
  viewVector(result);
  return 0;
}
