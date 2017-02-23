#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  int maxArea(vector<int>& height) {
    int left = 0, right = height.size()-1;
    int maxvol = 0;
    while(left < right){
      int h = min(height[left], height[right]);
      maxvol = max(maxvol, (right - left)*h);
      while(height[left] <= h && left < right) left++;
      while(height[right] <= h && left < right) right--;
    }
    return maxvol;
  }
};

int main(void){
  vector<int> height;
  readVector(height);
  Solution solution;
  int maxvol = solution.maxArea(height);
  cout << "Max area is " << maxvol << endl;
  return 0;
}
