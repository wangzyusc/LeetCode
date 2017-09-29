#include "../IOLib.hpp"

class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        unordered_map<char, int> str, window;
        for(auto c: t) str[c]++;
        int start = 0, end = 0;
        int minlen = s.size() + 1, count = 0;
        while(end < s.size()){
            char c = s[end];
            window[c]++;
            if(str.find(c) != str.end()){
                if(str[c] >= window[c]) count++;
            }
            if(count >= t.size()){
                while(str.find(s[start]) == str.end() ||
                      str[s[start]] < window[s[start]]){
                    window[s[start]]--;
                    start++;
                }
                if(end - start + 1 < minlen){
                    minlen = end - start + 1;
                    res = s.substr(start, minlen);
                }
            }
            end++;
        }
        return res;
    }
};

int main(void){
    string s = readString();
    string t = readString();
    Solution solution;
    string res = solution.minWindow(s, t);
    cout << res << endl;
    return 0;
}
