#include "../IOLib.hpp"

/***
Time: O(n)
Space: O(1)
***/

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> result;
        //if(s.length() < 2) return result;
        for(int i = 0; i + 1 < s.length(); i++){
            if(s[i] == '+' && s[i+1] == '+'){
                result.push_back(s.substr(0,i) + "--" + s.substr(i+2));
            }
        }
        return result;
    }
};
