#include "../IOLib.hpp"

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counts;
        for(auto c: s){
            counts[c]++;
        }
        bool single = false;
        int sum = 0;
        for(auto it: counts){
            sum += (it.second % 2)?(it.second-1):it.second;
            if(it.second & 1) single = true;
        }
        if(single) sum++;
        return sum;
    }
};
