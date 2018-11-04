#include <string>

class Solution {
public:
  string longestPalindrome(string s) {
    int length = s.size();
    if(length < 2) return s;
    bool map[length][length] = {false};
    for(int i = 0; i < length; i++){
      for(int j = 0; j < length; j++){
	if(i >= j) map[i][j] = true;
      }
    }
    int maxlen = 1;
    int maxl = 0;
    for(int len = 2; len <= length; len++){//k is length of string
      for(int left = 0; left + len <= length; left++){//left + len - 1 < length
	map[left][left + len - 1] = map[left+1][left+len-2] && (s[left] == s[left+len-1]);
	if(map[left][left+len-1] && len > maxlen){
	  maxlen = len;
	  maxl = left;
	}
      }
    }
    return s.substr(maxl, maxlen);
  }
};
