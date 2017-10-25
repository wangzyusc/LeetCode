#include "../IOLib.hpp"

/***
Boyer-Moore Majority Vote algorithm.
Time: O(n)
Space: O(1)
***/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        int x = INT_MAX, y = INT_MAX, countx = 0, county = 0;
        for(int num: nums){
            if(num == x) countx++;
            else if(num == y) county++;
            else if(countx == 0){
                x = num; countx++;
            }
            else if(county == 0){
                y = num; county++;
            }
            else{
                countx--;
                county--;
            }
        }
        countx = county = 0;
        for(int num: nums){
            if(num == x) countx++;
            else if(num == y) county++;
        }
        vector<int> res;
        if(countx > size / 3) res.push_back(x);
        if(y != x && county > size / 3) res.push_back(y);
        return res;
    }
};
