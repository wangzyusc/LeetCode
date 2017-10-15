#include "../IOLib.hpp"

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> dict;
        int i = 0, j = 0, res = 0;
        while(i < s.size()){
            dict[s[i]]++;
            while(dict.size() > k){
                dict[s[j]]--;
                if(dict[s[j]] == 0)
                    dict.erase(s[j]);
                j++;
            }
            if(i - j + 1 > res)
                res = i - j + 1;
            i++;
        }
        return res;
    }
};
