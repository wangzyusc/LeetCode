#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    string result = "";
    int num = strs.size();
    if(num == 0) return result;
    int minlen = strs[0].size();
    for(int i = 1; i < num; i++){
      minlen = min(minlen, (int)strs[i].size());
    }
    for(int len = 1; len <= minlen; len++){
      string temp = strs[0].substr(0, len);
      int i;
      for(i = 1; i < num; i++){
	if(temp[len-1] != strs[i][len-1]) break;
      }
      if(i != num) return result;
      else result = temp;
    }
    return result;
  }
};

int main(void){
    vector<string> input;
    string line;
    getline(cin, line);
    istringstream stream(line);
    string str;
    while(stream >> str){
        input.push_back(str);
    }
    Solution solution;
    string output = solution.longestCommonPrefix(input);
    cout << output << endl;
    return 0;
}
