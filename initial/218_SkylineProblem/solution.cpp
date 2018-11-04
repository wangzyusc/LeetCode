#include "../IOLib.hpp"

/***
Use a multiset to store all heights still active.
If there's a new building, put the height into set, if the max height in set has changed, put the (x, height) pair into result.
If the building ends, first delete height, if max height changes, put the (x, new max height) into result.
So in conclusion, insert and delete heights into multisets. If max height changes, put (x, h) pair into result.
Time: O(n)
Space: O(n)
***/

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> walls;
        for(auto nums: buildings){
            walls.push_back(make_pair(nums[0], -nums[2]));
            walls.push_back(make_pair(nums[1], nums[2]));
        }
        sort(walls.begin(), walls.end());
        int pre = 0, cur;
        vector<pair<int, int>> result;
        multiset<int> height;
        height.insert(0);
        for(auto w: walls){
            if(w.second < 0){
                height.insert(-w.second);
            }
            else{
                height.erase(height.find(w.second));
            }
            cur = *height.rbegin();
            if(pre != cur){
                result.push_back(make_pair(w.first, cur));
                pre = cur;
            }
        }
        return result;
    }
};
