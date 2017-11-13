#include "../IOLib.hpp"

/***
Power of two should only have 1 digit of 1, so if removed the last 1, it should be 0,
otherwise it's not power of two.
***/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return !(n - (n & -n));
    }
};
