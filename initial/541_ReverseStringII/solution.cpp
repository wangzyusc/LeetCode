#include "../IOLib.hpp"

/***
Two pointers.
Time: O(n)
Space: O(1)
***/
class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0, j = 0;
        while(i < s.size()){
            if((i - j == k - 1) || ((i == s.size() - 1) && (i - j <= k - 1))){
                for(int l = j, r = i; l < r; l++, r--)
                    swap(s[l], s[r]);
            }
            else if(i - j == 2 * k){
                j = i;
            }
            i++;
        }
        return s;
    }
};
