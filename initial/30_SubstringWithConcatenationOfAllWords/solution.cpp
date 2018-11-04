#include "../IOLib.hpp"

/**
Brute force solution.
Time: O(s.length * words.length * word.length)
Space: O(words.length * word.length)
**/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(words.empty()) return result;
        int len = words[0].length();
        int totlen = len * words.size();
        for(int i = 0; i < s.size() - totlen + 1; i++){
            unordered_map<string, int> dict;
            for(auto w: words) dict[w]++;
            bool valid = true;
            for(int j = 0; j < words.size(); j++){
                string cur = s.substr(i + len * j, len);
                if(dict.find(cur) == dict.end() || dict[cur] == 0){
                    valid = false;
                    break;
                }
                else dict[cur]--;
            }
            if(valid) result.push_back(i);
        }
        return result;
    }
};
