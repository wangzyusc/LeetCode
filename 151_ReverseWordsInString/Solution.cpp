#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  void reverseWords(string &s) {
    vector<string> lib;
    int i = 0;
    bool pre = false;
    string current = "";
    while(i < s.size()){
      if(s[i] == ' '){
	if(pre){
	  lib.push_back(current);
	  current = "";
	}
	pre = false;
      }
      else{
	current += s[i];
	pre = true;
	if(i == s.size()-1){
	  lib.push_back(current);
	}
      }
      i++;
    }
    s = "";
    for(int i = lib.size()-1; i >= 0; i--){
      s += lib[i];
      if(i) s += " ";
    }
  }
};

int main(void){
  string line = readString();
  printString(line);
  Solution solution;
  solution.reverseWords(line);
  printString(line);
  return 0;
}
