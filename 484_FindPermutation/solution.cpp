#include "../IOLib.hpp"

/***
Reverse subarray.
Or use stack: For each iteration, push i into stack. 
              When 'I', pop all numbers out and put into array;
              When 'D', don't do anything. 
There's also a two-pointer method.
Time: O(n)
Space: O(1) (or O(n) for stack method)
***/
class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> result(s.length() + 1);
        for(int i = 0; i < result.size(); i++){
            result[i] = i+1;
        }
        for(int i = 0; i < s.size(); i++){
            int j = i;
            while(j < s.size() && s[j] == 'D')
                j++;
            reverse(result.begin() + i, result.begin() + j + 1);
            i = j;
        }
        return result;
    }
};
