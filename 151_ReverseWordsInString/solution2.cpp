#include "../IOLib.hpp"

class Solution {
public:
    void reverseWords(string &s) {
        stack<string> words;
        int start = -1, end = 0;
        bool inword = false;
        for(int i = 0; i <= s.size(); i++){
            if((i == s.size() || s[i] == ' ') && inword){
                end = i - 1;
                words.push(s.substr(start, end - start + 1));
                inword = false;
            }
            else if(i < s.size() && s[i] != ' ' && !inword){
                start = i;
                inword = true;
            }
        }
        s = "";
        while(!words.empty()){
            s += " " + words.top();
            words.pop();
        }
        if(!s.empty()) s = s.substr(1);
    }
};

int main(void){
    Solution sol;
    string input = readString();
    sol.reverseWords(input);
    cout << "Result is \"" << input << "\"" << endl;
    return 0;
}
