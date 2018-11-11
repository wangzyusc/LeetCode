#include "../../IOLib.hpp"

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        vector<char> str;
        for(auto c: S){
            if(c != '-')
                str.push_back(toupper(c));
        }
        int num = str.size() % K;
        string res;
        auto it = str.begin();
        if(num){
            res += string(it, it + num) + "-";
        }
        for(int start = num; start < str.size(); start += K){
            res += string(it + start, it + start + K) + "-";
        }
        return res.substr(0, res.size() - 1);
    }
};
