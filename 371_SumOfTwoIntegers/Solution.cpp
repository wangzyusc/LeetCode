#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  int getSum(int a, int b) {
    int sumByBit = a ^ b;
    int carryByBit = a & b;
    //in my memory there is a variable to store carries,
    //while the carries are not 0, continue the computation
    while(carryByBit){
      carryByBit <<= 1;
      int tempCarry = sumByBit & carryByBit;
      sumByBit = sumByBit ^ carryByBit;
      carryByBit = tempCarry;
    }
    return sumByBit;
  }
};

int main(void){
  int a = readInt();
  int b = readInt();
  Solution solution;
  cout << a << " + " << b << " = " << solution.getSum(a,b) << endl;
  return 0;
}
