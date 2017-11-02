#include "../IOLib.hpp"

/***
Backtracking.
Time: O(2^n)
Space: O(n)
***/

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        helper(result, word, "", 0);
        return result;
    }
    void helper(vector<string>& result, string& word, string prev, int pos){
        if(pos == word.size()){
            result.push_back(prev);
            return;
        }
        helper(result, word, prev + word[pos], pos+1);
        if(!isdigit(prev[prev.size() - 1])){
            for(int i = 1; i <= word.size() - pos; i++){
                helper(result, word, prev + to_string(i), pos + i);
            }
        }
    }
};
