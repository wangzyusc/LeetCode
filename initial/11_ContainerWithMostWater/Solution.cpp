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

/* A more concise version */
class Solution2 {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int l = 0, r = height.size() - 1;
        while(l < r){
            water = max(water, (r - l) * min(height[l], height[r]));
            if(height[l] < height[r])
                l++;
            else
                r--;
        }
        return water;
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
