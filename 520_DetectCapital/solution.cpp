#include "../IOLib.hpp"

/***
Time: O(n)
Space: O(1)
***/
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() < 2) return true;
        bool firstCapital = (word[0] >= 'A') && (word[0] <= 'Z');
        bool secondCapital = (word[1] >= 'A') && (word[1] <= 'Z');
        if(!firstCapital && secondCapital) return false;
        for(int i = 2; i < word.size(); i++)
            if(((word[i] >= 'A') && (word[i] <= 'Z')) != secondCapital) return false;
        return true;
    }
};
