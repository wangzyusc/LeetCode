#include "../IOLib.hpp"

/* Easy solution: use a 256-array as hashmap to count.
 * First iteration to count each char, second iteration
 * to find the first char with count equal to 1.
 */
class Solution {
public:
    int firstUniqChar(string s) {
        int counts[256] = {0};
        for(char c: s){
            counts[c]++;
        }
        for(int i = 0; i < s.size(); i++){
            if(counts[s[i]] == 1) return i;
        }
        return -1;
    }
};
