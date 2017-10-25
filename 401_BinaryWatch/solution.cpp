#include "../IOLib.hpp"

/***
Similar to combination sum.
Be careful with hour over 12 or minutes over 60.
Time: O(n!)
Space: O(n!)
***/

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<int> mins{800, 400, 200, 100, 32, 16, 8, 4, 2, 1};
        reverse(mins.begin(), mins.end());
        vector<int> sums;
        combine(sums, mins, 0, 0, num);
        sort(sums.begin(), sums.end());
        vector<string> res;
        for(int sum: sums){
            int h = sum / 100, m = sum % 100;
            if(h >= 12 || m >= 60) continue;
            res.push_back(to_string(h) + ":" + ((m < 10)?"0":"") + to_string(m));
        }
        return res;
    }
    void combine(vector<int>& sums, const vector<int>& mins, int sum, int start, int num){
        if(num == 0){
            sums.push_back(sum);
            return;
        }
        for(int i = start; i < mins.size(); i++){
            combine(sums, mins, sum + mins[i], i + 1, num - 1);
        }
    }
};
