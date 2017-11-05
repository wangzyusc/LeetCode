#include "../IOLib.hpp"

/***
Time: O(n)
Space: O(1)
***/

class Solution {
public:
    string addStrings(string num1, string num2) {
        string result(max(num1.length(), num2.length()) + 1, '0');
        int i = num1.length() - 1, j = num2.length() - 1, k = result.length() - 1;
        int carry = 0, sum;
        while(i >= 0 || j >= 0 || carry){
            sum = ((i>=0)?(num1[i]-'0'):0) + ((j>=0)?(num2[j]-'0'):0) + carry;
            carry = sum / 10;
            sum %= 10;
            result[k] = '0' + sum;
            k--; j--; i--;
        }
        if(result.length() > 1 && result[0] == '0') result = result.substr(1);
        return result;
    }
};
