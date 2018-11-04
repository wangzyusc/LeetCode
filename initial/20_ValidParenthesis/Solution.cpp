#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    int length = s.size();
    if(length == 0) return true;
    if(length % 2 == 1) return false;
    stack<char> paren;
    for(int i = 0; i < length; i++){
      char c = s[i];
      if(c == '(' || c == '{' || c == '[') paren.push(c);
      else if(paren.empty()){//paren is empty
	return false;
      }
      else{
	char top = paren.top();
	if(c == ')' && top == '(') paren.pop();
	else if(c == '}' && top == '{') paren.pop();
	else if(c == ']' && top == '[') paren.pop();
	else return false;
      }
    }
    if(!paren.empty()) return false;
    return true;
  }
};

//Slightly more concise version.
class Solution1 {
public:
    bool isValid(string s) {
        stack<char> prev;
        for(auto c: s){
            switch(c){
                case '(': prev.push(c); break;
                case '[': prev.push(c); break;
                case '{': prev.push(c); break;
                case ')': if(prev.empty() || prev.top() != '(') return false; prev.pop(); break;
                case ']': if(prev.empty() || prev.top() != '[') return false; prev.pop(); break;
                case '}': if(prev.empty() || prev.top() != '{') return false; prev.pop(); break;
                default: break;
            }
        }
        return prev.empty();
    }
};

int main(int argc, char* argv[]){
    if(argc != 2){
        cout << "Number of Input parameters wrong!" << endl;
        return -1;
    }
    string input = argv[1];
    Solution solution;
    cout << solution.isValid(input) << endl;
    return 0;
}
