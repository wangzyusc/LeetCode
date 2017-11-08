#include "../IOLib.hpp"

/***
Most brute force method.
Could also use backtracking, each time combine two elements in array to one value,
until there's only 1 value in that array.
Time: O(4! * 12 * 8 * 4) = O(9216) = O(1)
Space: O(4+3+2+1) = O(1)
***/
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> numbers(nums.begin(), nums.end());
        sort(numbers.begin(), numbers.end());
        do{
            if(valid(numbers[0], numbers[1], numbers[2], numbers[3]))
                return true;
        } while(next_permutation(numbers.begin(), numbers.end()));
        return false;
    }
    bool valid(double a, double b, double c, double d){
        if(valid(a+b,c,d) || valid(a-b,c,d) || valid(a*b,c,d) || valid(a/b,c,d) ||
           valid(a,b+c,d) || valid(a,b-c,d) || valid(a,b*c,d) || valid(a,b/c,d) ||
           valid(a,b,c+d) || valid(a,b,c-d) || valid(a,b,c*d) || valid(a,b,c/d))
            return true;
        return false;
    }
    bool valid(double a, double b, double c){
        if(valid(a+b, c) || valid(a-b, c) || valid(a*b, c) || (b != 0 && valid(a/b, c)) ||
           valid(a, b+c) || valid(a, b-c) || valid(a, b*c) || (c != 0 && valid(a, b/c)))
            return true;
        return false;
    }
    bool valid(double a, double b){
        if(abs(a + b - 24) < 0.0001 || abs(a - b - 24) < 0.0001 || abs(a * b - 24) < 0.0001 || (b != 0 && abs(a / b - 24) < 0.0001)) return true;
        return false;
    }
};
