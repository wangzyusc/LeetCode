#include "../IOLib.hpp"

/***
Using hashmap to get the number of kinds of candies.
Then return minimum of this number and the number of candies she can get.
Time: O(n)
Space: O(1)
***/
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int, int> counts;
        for(auto n: candies){
            counts[n]++;
        }
        return min(counts.size(), candies.size() / 2);
    }
};
