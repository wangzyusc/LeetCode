#include <iostream>

using namespace std;

class Solution {
public:
  int reverse(int x) {
    long long result = 0;
    while(x != 0){
      result = 10 * result + x % 10;
      x /= 10;
    }
    return (result > INT_MAX || result < INT_MIN)? 0 : (int)result;
  }
};

int main(int argc, char* argv[]){
    if(argc != 2){
      cout << "Number of Input Arguments WRONG!" << endl;
      return -1;
    }
    string num(argv[1]);
    int input = atoi(num.c_str());
    Solution solution;
    int result = solution.reverse(input);
    cout << result << endl;
    return 0;
}
