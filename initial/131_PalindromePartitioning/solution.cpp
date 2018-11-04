#include "../IOLib.hpp"

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> prev;
        backtrack(result, prev, s);
        return result;
    }
    void backtrack(vector<vector<string>>& result, vector<string>& prev, string s){
        if(s.empty())
            result.push_back(prev);
        for(int i = 1; i <= s.size(); i++){
            int l = 0, r = i - 1;
            while(l < r){
                if(s[l] != s[r]) break;
                l++; r--;
            }
            if(l < r) continue;
            prev.push_back(s.substr(0, i));
            backtrack(result, prev, s.substr(i));
            prev.pop_back();
        }
    }
};

int main(void){
    string s = readString();
    Solution sol;
    auto result = sol.partition(s);
    for(auto line: result)
        printVector(line);
    return 0;
}
