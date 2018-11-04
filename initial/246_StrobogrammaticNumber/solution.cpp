#include "../IOLib.hpp"

/**
Use a hashmap to do mapping between characters.
Time: O(n)
Space: O(1)
**/

class Solution {
public:
    bool isStrobogrammatic(string num) {
        if(num.empty()) return true;
        unordered_map<char, char> dict{{'1','1'},{'2','#'},{'3','#'},{'4','#'},{'5','#'},{'6','9'},{'7','#'},{'8','8'},{'9','6'},{'0','0'}};
        int i = 0, j = num.size() - 1;
        while(i <= j){
            if(num[j--] != dict[num[i++]]) return false;
        }
        return true;
    }
};
