#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    int stairs[n];
    stairs[n-1] = 1;
    if(n > 1) stairs[n - 2] = 2;
    for(int i = n-3; i >= 0; i--){
      stairs[i] = stairs[i+1] + stairs[i+2];
    }
    return stairs[0];
  }
};

int main(){
  int n = readInt();
  Solution solution;
  cout << "The total number of distinct ways is " << solution.climbStairs(n) << endl;
  return 0;
}
