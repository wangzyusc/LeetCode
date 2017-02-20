#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  string reverseString(string s) {
    int len = s.length();
    for(int i = 0; i < len/2; i++){
      char c = s[i];
      s[i] = s[len-1-i];
      s[len-1-i] = c;
    }
    return s;
  }
};

int main(void){
  string s;
  getline(cin, s);
  Solution solution;
  cout << solution.reverseString(s) << endl;
  return 0;
}
