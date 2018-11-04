#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
  vector<vector<int> > fourSum(vector<int>& nums, int target) {
    int length = nums.size();
    vector<vector<int> > result;
    if(length < 4) return result;
    sort(nums.begin(), nums.end());
    cout << "After sorting the array is: [";
    for(int i = 0; i < length; i++){
        cout << nums[i];
	if(i < length - 1) cout << ", ";
	else cout << "]" << endl;
    }
    for(int i = 0; i < length - 3; i++){
      while(i > 0 && (i < length - 3) && (nums[i] == nums[i-1])) i++;
      for(int j = i+1; j < length - 2; j++){
	while((j > i+1) && (j < length - 2) && (nums[j] == nums[j-1])) j++;
	int start = j+1, end = length-1;
	int sum = target - nums[i] - nums[j];
	while(start < end){
	  if(nums[start] + nums[end] == sum){
	    vector<int> quad;
	    quad.push_back(nums[i]);
	    quad.push_back(nums[j]);
	    quad.push_back(nums[start]);
	    quad.push_back(nums[end]);
	    result.push_back(quad);
	    while(start < end && nums[start] == nums[start+1]) start++;
	    while(start < end && nums[end] == nums[end-1]) end--;
	    start++; end--;
	  }
	  else if(nums[start] + nums[end] < sum){
	    while(start < end && nums[start] == nums[start+1]) start++;
	    start++;
	  }
	  else{//nums[start] + nums[end] > sum
	    while(start < end && nums[end] == nums[end-1]) end--;
	    end--;
	  }
	}
      }
    }
    return result;
  }
};

int main(void){
    string line;
    int num, target;
    vector<int> input;
    cout << "Input array numbers: " << endl;
    getline(cin, line);
    cout << "Input target number:" << endl;
    cin >> target;
    cout << "Target is " << target << endl;
    istringstream stream(line);
    while(stream >> num){
        input.push_back(num);
    }
    Solution solution;
    vector<vector<int> > result = solution.fourSum(input, target);
    cout << "[ ";
    for(int i = 0; i < result.size(); i++){
        cout << "[";
        for(int j = 0; j < 3; j++){
	    cout << result[i][j] << ", ";
	}
	cout << result[i][4] << "]";
	if(i < result.size()-1) cout << ", ";
	else cout << " ]" << endl;
    }
    return 0;
}
