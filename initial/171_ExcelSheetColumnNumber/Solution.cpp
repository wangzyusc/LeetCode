#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  int titleToNumber(string s) {
    int result = 0;
    for(int i = 0; i < s.size(); i++){
      result = 26 * result + (s[i] - 'A' + 1);
    }
    return result;
  }
};

int main(void){
  string s = readString();
  Solution solution;
  cout << "Column number is " << solution.titleToNumber(s) << endl;
  return 0;
}
