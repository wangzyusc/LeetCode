#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int length = nums.size();
    if(length == 0) return -1;
    int pivot = length - 1;
    int left = 0, right = length - 1;
    while(left < right - 1){
      if(nums[left] < nums[right]) break;
      int mid = (left + right) / 2;
      if(nums[mid] == target) return mid;
      if(nums[mid] > nums[0]){
	left = mid;
      }
      else if(nums[mid] < nums[length-1]){
	right = mid;
      }
    }
    if(left + 1 == right){
      if(nums[left] < nums[right]) pivot = left - 1;
      else if(nums[left] > nums[right]) pivot = left;
    }
    else{
      pivot = right;
    }
    if(pivot == length - 1){
      left = 0;
      right = pivot;
    }
    else if(target == nums[0]){
      return 0;
    }
    else if(target < nums[0]){
      left = pivot + 1;
      right = length - 1;
    }
    else{//target > nums[0]
      left = 1;
      right = pivot;
    }
    while(left < right){
      int mid = (left + right) / 2;
      if(nums[mid] == target) return mid;
      if(nums[mid] < target) left = mid + 1;
      if(nums[mid] > target) right = mid;
    }
    if(nums[left] == target) return left;
    if(nums[right] == target) return right;
    return -1;
  }
};

int main(){
  vector<int> input;
  readVector(input);
  int target = readInt();
  Solution solution;
  cout << "The result is " << solution.search(input, target) << endl;
  return 0;
}
