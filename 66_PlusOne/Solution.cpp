#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    //vector<int>::iterator it = result.begin();
    int length = digits.size();
    int fwd = 1;
    for(int i = length - 1; i >= 0; i--){
      int sum = digits[i] + fwd;
      digits[i] = sum % 10;
      fwd = sum / 10;
      if(fwd == 0) break;
    }
    if(fwd != 0){
        vector<int>::iterator it = digits.begin();
        digits.insert(it, fwd);
    }
    return digits;
  }
};

int main(){
    vector<int> src;
    int num = readInt();
    while(num != 0){
        src.push_back(num % 10);
	num /= 10;
    }
    reverse(src.begin(), src.end());
    viewVector(src);
    Solution solution;
    vector<int> dst = solution.plusOne(src);
    cout << "After plus one: " << endl;
    viewVector(dst);
    return 0;
}
