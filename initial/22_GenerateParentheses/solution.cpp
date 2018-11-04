#include "../IOLib.hpp"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string seed;
        generator(result, seed, n, 0);
        return result;
    }
    void generator(vector<string>& result, string seed, int left, int right){
        if(left == 0){
            if(right == 0) result.push_back(seed);
            else generator(result, seed + ")", left, right-1);
            return;
        }
        if(left > 0) generator(result, seed + "(", left-1, right+1);
        if(right > 0) generator(result, seed + ")", left, right-1);
    }
};

int main(void){
    int n = readInt();
    Solution sol;
    auto res = sol.generateParenthesis(n);
    printVector(res);
    return 0;
}
