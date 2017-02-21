#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    while(n){
      count += n % 2;
      n >>= 1;
    }
    return count;
  }
};

int main(void){
  int num = readInt();
  Solution solution;
  cout << "The number of 1 bits in num is " << solution.hammingWeight((uint32_t)num) << endl;
  return 0;
}
