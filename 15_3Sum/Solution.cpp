#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
  vector<vector<int> > threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    vector<vector<int> > result;
    if(len < 3 || nums[0] > 0 || nums[len-1] < 0) return result;
    for(int i = 0; i < len - 2; i++){
      for(int j = i+1; j < len - 1; j++){
	bool repeat = false;
	for(int k = 0; k < result.size(); k++){
	  if(result[k][0] == nums[i] && result[k][1] == nums[j]){
	    repeat = true;
	  }
	}
	if(repeat) continue;
	int start = j+1, end = len-1;
	int target = -(nums[i]+nums[j]);
	while(start < end){
	  int mid = (start + end)/2;
	  if(nums[mid] == target){
	    vector<int> item;
	    item.push_back(nums[i]);
	    item.push_back(nums[j]);
	    item.push_back(target);
	    result.push_back(item);
	    break;
	  }
	  else if(nums[mid] < target){
	    start = mid + 1;
	  }
	  else{
	    end = mid;
	  }
	}
	if(start == end && nums[start] == target){
	  vector<int> item;
	  item.push_back(nums[i]);
	  item.push_back(nums[j]);
	  item.push_back(target);
	  result.push_back(item);
	}
      }
    }
    return result;
  }
};

int main(void){
  int num;
  string line;
  vector<int> input;
  cout << "Enter input numbers:" << endl;
  getline(cin, line);
  istringstream stream(line);
  while(stream >> num){
    input.push_back(num);
  }
  Solution solution;
  vector<vector<int> > output = solution.threeSum(input);
  for(int i = 0; i < output.size(); i++){
    cout << "[" << output[i][0] << ", " << output[i][1] << ", " << output[i][2] << "]" << endl;
  }
}
