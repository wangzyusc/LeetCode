#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        int last = 1, current;
        if(n > 1) current = 2;
        for(int i = n-3; i >= 0; i--){
            int temp = current;
            current += last;
            last = temp;
        }
        return current;
    }
};

int main(){
  int n = readInt();
  Solution solution;
  cout << "The total number of distinct ways is " << solution.climbStairs(n) << endl;
  return 0;
}
