#include "../IOLib.hpp"

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(abs((int)(s.size() - t.size())) > 1) return false;
        //so that the length difference is at most 1
        if(s.size() > t.size()) swap(s, t);
        //so that s.size() <= t.size()
        bool diff = false;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != t[i]){
                if(s.size() == t.size()) s[i] = t[i];
                else s = s.substr(0, i) + t[i] + s.substr(i);
                diff = true;
                break;
            }
        }
        return diff ? (s == t) : (t.size() == s.size() + 1);
    }
};

int main(void){
    string s = readString();
    string t = readString();
    Solution solution;
    bool is = solution.isOneEditDistance(s, t);
    cout << "\"" << s << "\" and \"" << t
         << "\" is " << (is?"":"not ")
         << "one edit distance."<< endl;
    return 0;
}
