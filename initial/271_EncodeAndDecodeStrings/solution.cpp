#include "../IOLib.hpp"

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result;
        for(auto str: strs){
            result += (to_string((long)str.length()) + "|" + str); // merge 3 "result += ..." into 1 would make it faster
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        long idx = 0;
        while(idx < (long)s.size()){
            long len = 0;
            while(isdigit(s[idx])){
                len = len * 10 + s[idx++] - '0';
            }
            result.push_back(s.substr(idx, len+1).substr(1));
            idx += (len + 1);
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
