#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  int trap(vector<int>& height) {
    int left = 0, right = height.size()-1;
    int water = 0;
    int maxleft = 0, maxright = 0;
    while(left <= right){
      if(height[left] <= height[right]){
	if(height[left] < maxleft) water += (maxleft - height[left]);
	else maxleft = height[left];
	left++;
      }
      else{
	if(height[right] < maxright) water += (maxright - height[right]);
	else maxright = height[right];
	right--;
      }
    }
    return water;
  }
};

int main(void){
  vector<int> height;
  readVector(height);
  Solution solution;
  int water = solution.trap(height);
  cout << "The trapped water is " << water << endl;
  return 0;
}
