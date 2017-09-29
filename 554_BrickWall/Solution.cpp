#include "../IOLib.hpp"

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> counts;
        for(auto row: wall){
            int sum = 0;
            for(int i = 0; i < row.size() - 1; i++){
                sum += row[i];
                counts[sum]++;
            }
        }
        int maxedge = 0;
        for(auto it = counts.begin(); it != counts.end(); it++){
            if(it->second > maxedge) maxedge = it->second;
        }
        return wall.size() - maxedge;
    }
};

int main(void){
    return 0;
}
