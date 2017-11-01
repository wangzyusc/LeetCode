#include "../IOLib.hpp"

/***
Time: O(n)
Space: O(1)
***/
class Solution {
public:
    string reverseWords(string s) {
        if(s.size() < 2) return s;
        int i = 0, j = 0;
        while(i <= s.size()){
            if(i == s.size() || s[i] == ' '){
                int temp = i - 1;
                while(j < temp){
                    swap(s[j], s[temp]);
                    j++; temp--;
                }
                j = ++i;
            }
            else{
                i++;
                continue;
            }
        }
        return s;
    }
};
