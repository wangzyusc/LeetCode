#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  string intToRoman(int num) {
    string result = "";
    int thr[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string roman[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    for(int i = 0; i < 13; i++){
      while(num >= thr[i]){
	result += roman[i];
	num -= thr[i];
      }
    }
    return result;
  }
};

int main(void){
  int num = readInt();
  while(num < 1 && num > 3999)
    num = readInt();
  Solution solution;
  cout << "The roman expression for number " << num << " is "
       << solution.intToRoman(num) << endl;
  return 0;
}
