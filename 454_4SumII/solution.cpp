#include "../IOLib.hpp"

/***
Time complexity: O(n^2)
Space complexity: O(n^2)
***/
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> sums;
        for(auto a: A){
            for(auto b: B){
                sums[a+b]++;
            }
        }
        int result = 0;
        for(auto c: C){
            for(auto d: D){
                if(sums.find(-c-d) != sums.end())
                    result += sums[-c-d];
            }
        }
        return result;
    }
};
