#include <vector>
#include <iostream>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> result;
    int length = digits.size();
    if(length == 0) return result;
    vector<vector<string> > strs;
    vector<string> s0;
    s0.push_back("");
    strs.push_back(s0);
    for(int i = 0; i < length; i++){
      vector<string> si;
      char digit = digits[i];
      addNewLetter(si, strs, digit);
      if(i == length-1) return si;
      strs.push_back(si);
    }
    return strs[length];
  }
  void addNewLetter(vector<string>& si, vector<vector<string> >& strs, char c){
    int depth = strs.size();
    int len = strs[depth-1].size();
    for(int i = 0; i < len; i++){
      //si.push_back(strs[depth-1][i] + "");
      if(c == '1'){
	si.push_back(strs[depth-1][i] + "");
      }
      else if(c == '2'){
	si.push_back(strs[depth-1][i] + "a");
	si.push_back(strs[depth-1][i] + "b");
	si.push_back(strs[depth-1][i] + "c");
      }
      else if(c == '3'){
	si.push_back(strs[depth-1][i] + "d");
	si.push_back(strs[depth-1][i] + "e");
	si.push_back(strs[depth-1][i] + "f");
      }
      else if(c == '4'){
	si.push_back(strs[depth-1][i] + "g");
	si.push_back(strs[depth-1][i] + "h");
	si.push_back(strs[depth-1][i] + "i");
      }
      else if(c == '5'){
	si.push_back(strs[depth-1][i] + "j");
	si.push_back(strs[depth-1][i] + "k");
	si.push_back(strs[depth-1][i] + "l");
      }
      else if(c == '6'){
	si.push_back(strs[depth-1][i] + "m");
	si.push_back(strs[depth-1][i] + "n");
	si.push_back(strs[depth-1][i] + "o");
      }
      else if(c == '7'){
	si.push_back(strs[depth-1][i] + "p");
	si.push_back(strs[depth-1][i] + "q");
	si.push_back(strs[depth-1][i] + "r");
	si.push_back(strs[depth-1][i] + "s");
      }
      else if(c == '8'){
	si.push_back(strs[depth-1][i] + "t");
	si.push_back(strs[depth-1][i] + "u");
	si.push_back(strs[depth-1][i] + "v");
      }
      else if(c == '9'){
	si.push_back(strs[depth-1][i] + "w");
	si.push_back(strs[depth-1][i] + "x");
	si.push_back(strs[depth-1][i] + "y");
	si.push_back(strs[depth-1][i] + "z");
      }
      else{//c == '0'
	si.push_back(strs[depth-1][i] + " ");
      }
    }
  }
};

int main(int argc, char* argv[]){
    if(argc != 2){
        cout << "Number of input arguments wrong!" << endl;
	return -1;
    }
    string input(argv[1]);
    Solution solution;
    vector<string> result = solution.letterCombinations(input);
    cout << "[";
    for(int i = 0; i < result.size(); i++){
        cout << result[i];
	if(i != result.size()-1){
	    cout << ", ";
	}
	else{
	  cout << "]" << endl;
	}
    }
    return 0;
}
