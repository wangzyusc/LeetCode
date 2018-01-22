#include "../IOLib.hpp"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = (m == 0) ? 0 : obstacleGrid[0].size();
        if(!m || !n) return 0;
        vector<int> slots(n, 0);
        slots[0] = 1;
        for(int i = 0; i < m; i++){
            slots[0] = (obstacleGrid[i][0] == 0 && slots[0] == 1) ? 1: 0;
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j])
                    slots[j] = 0;
                else
                    slots[j] += slots[j-1];
            }
        }
        return slots[n-1];
    }
};

int main(void){
    vector<vector<int>> grid = readMatrix();
    Solution sol;
    int num_paths = sol.uniquePathsWithObstacles(grid);
    cout << "Unique paths = " << num_paths << endl;
    return 0;
}
