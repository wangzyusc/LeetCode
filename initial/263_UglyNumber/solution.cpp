#include "../IOLib.hpp"

class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0) return false;
        while(num > 1 && !(num & 1)){
            num /= 2;
        }
        while(num > 1 && (num % 3 == 0))
            num /= 3;
        while(num > 1 && (num % 5 == 0))
            num /= 5;
        return num == 1;
    }
};

/**
More concise version.
**/
class Solution {
public:
    bool isUgly(int num){
        if(num <= 0) return false;
        for(auto b: base){
            while(num % b == 0)
                num /= b;
        }
        return num == 1;
    }
private:
    vector<int> base{2,3,5};
};
