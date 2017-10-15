#include "../IOLib.hpp"

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        stringstream ss(S);
        string item, input;
        while(getline(ss, item, '-')){
            input += item;
        }
        //input = toupper(input);
        for(auto &c: input)
            c = toupper(c);
        string res;
        while(input.size() > K){
            res = "-" + input.substr(input.size() - K) + res;
            input = input.substr(0, input.size() - K);
        }
        if(input.size()) res = input + res;
        return res;
    }
};
