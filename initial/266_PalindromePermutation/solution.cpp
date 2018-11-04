#include "../IOLib.hpp"

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> counts;
        for(auto c: s){
            counts[c]++;
        }
        bool single = false;
        for(auto it: counts){
            if((it.second & 1) == 1){
                if(single) return false;
                single = true;
            }
        }
        return true;
    }
};
