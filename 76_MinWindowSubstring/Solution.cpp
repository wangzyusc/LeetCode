#include "../IOLib.hpp"

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        unordered_map<char, int> dict;
        for(char c: t){
            dict[c]++;
        }
        unordered_map<char, int>::iterator it = dict.begin();
        for(int length = t.size(); length <= s.size(); length++){
            unordered_map<char, int> superdict;
            for(int pos = 0; pos < length-1; pos++) superdict[s[pos]]++;
            for(int i = 0; i+length <= s.size(); i++){
                if(i > 0) superdict[s[i-1]]--;
                superdict[s[i+length-1]]++;
                for(it = dict.begin(); it != dict.end(); it++){
                    if(superdict[it->first] < it->second) break;
                }
                if(it == dict.end()) return s.substr(i, length);
            }
        }
        return "";
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
