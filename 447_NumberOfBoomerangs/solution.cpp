#include "../IOLib.hpp"

/**
Hashmap.
Time: O(n^2)
Space: O(n)
**/

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int result = 0;
        for(int i = 0; i < points.size(); i++){
            unordered_map<int, int> dists;
            for(int j = 0; j < points.size(); j++){
                if(i != j)
                    dists[pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2)]++;
            }
            for(auto it: dists){
                if(it.second > 1)
                    result += it.second * (it.second - 1);
            }
        }
        return result;
    }
};
