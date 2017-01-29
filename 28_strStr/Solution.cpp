#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    int len1 = haystack.size(), len2 = needle.size();
    if(len1 == 0 && len2 == 0) return 0;
    if(len2 > len1) return -1;
    for(int i = 0; i <= len1 - len2; i++){
      int j = 0;
      for(; j < len2; j++){
	if(haystack[i+j] != needle[j]) break;
      }
      if(j == len2) return i;
    }
    return -1;
  }
};

int main(){
    string haystack, needle;
    cout << "Input haystack: ";
    cin >> haystack;
    cout << "Input needle: ";
    cin >> needle;
    Solution solution;
    int pos = solution.strStr(haystack,needle);
    cout << "The result is " << pos << endl;
    return 0;
}
