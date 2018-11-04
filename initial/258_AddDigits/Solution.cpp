#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  int addDigits(int num) {
    return 1 + (num - 1) % 9;
  }
};

int main(void){
  int num = readInt();
  Solution solution;
  cout << "Number " << num << " finally add to " << solution.addDigits(num) << endl;
  return 0;
}
