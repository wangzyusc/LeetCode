#include "../IOLib.hpp"

class Solution {
public:
    bool isMatch(string s, string p) {
        if(s == p) return true;
        if(p.size() == 0){
            return s.size() == 0;
        }
        bool first_match = (!s.empty()) &&
            ((p[0] == s[0]) || (p[0] == '.'));
        if(p.size() >= 2 && p[1] == '*'){
            return (first_match && isMatch(s.substr(1), p)) ||
                isMatch(s, p.substr(2));
        }
        else{
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }
};

int main(void){
    string text = readString();
    string pattern = readString();
    Solution sol;
    cout << (sol.isMatch(text, pattern)?"true":"false") << endl;
    return 0;
}
