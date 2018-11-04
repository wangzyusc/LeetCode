#include "../IOLib.hpp"

/***
Steps:
1.Find how many digits.
2.Find which exact number.
3.Find the exact digit.
Time: O(log(n))
Space: O(1)
***/
class Solution {
public:
    int findNthDigit(int n) {
        long curdigit = 0, sumdigit = 0, lastsum = 0;
        while(sumdigit < n){
            curdigit++;
            lastsum = sumdigit;
            sumdigit += curdigit * (pow(10, curdigit) - pow(10, curdigit-1));
        }
        int bias = n - lastsum;
        int num = pow(10, curdigit-1) - 1 + ceil(bias * 1.0 / curdigit);
        int digit = bias % curdigit;
        if(digit == 0) digit = curdigit;
        digit--;
        return to_string(num)[digit]-'0';
    }
};
