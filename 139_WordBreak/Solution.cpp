#include "../IOLib.hpp"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        int maxlen = 0, minlen = INT_MAX;
        int size = s.size();
        for(auto str: wordDict){
            dict.insert(str);
            maxlen = max(maxlen, (int)str.size());
            minlen = min(minlen, (int)str.size());
        }
        vector<bool> status(size, false);
        for(int i = 0; i < (size - minlen + 1); i++){
            if(i > 0 && !status[i - 1]) continue;
            for(int len = minlen; len <= maxlen; len++){
                string str = s.substr(i, len);
                if(dict.find(str) != dict.end())
                    status[i+len-1] = true;
            }
        }
        return status.back();
    }
};

int main(void){
    cout << "Target word: ";
    string s = readString();
    cout << "Dict length: ";
    int len = readInt();
    cout << "Word dict: " << endl;
    vector<string> wordDict = readVectorOfStrings(len);
    Solution solution;
    bool res = solution.wordBreak(s, wordDict);
    cout << "The word can " << (res?"":"not ") << "be broken with dict." << endl;
}
