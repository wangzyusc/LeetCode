#include "../IOLib.hpp"

/**
It's right to use recursion. But maybe no need to handle "0".
Can do it outside of backtrack().
Time: O(2^n)
Space: O(1)
**/

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        string str(n, '-');
        vector<string> res;
        vector<pair<char, char>> dict{{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}};
        backtrack(res, str, dict, 0, (n%2)?(n/2):(n/2-1));
        return res;
    }
    void backtrack(vector<string>& res, string str,
                   const vector<pair<char, char>>& dict,
                   int pos, const int& range){//range: size=4->range=1, size=5->range=2
        if(pos > range){
            res.push_back(str);
            return;
        }
        for(auto p: dict){
            //if pos == 0 and range > 0, skip '0' as first
            if(p.first == '0' && pos == 0 && str.size() >= 2) continue;
            //if in the middle point of odd length string, skip '6' and '9'
            if((p.first == '6' || p.first == '9') && str.size() % 2 && pos == range) continue;
            str[pos] = p.first;
            str[str.size() - pos - 1] = p.second;
            backtrack(res, str, dict, pos+1, range);
        }
    }
};
