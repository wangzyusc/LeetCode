#include "../IOLib.hpp"

/**
BFS. Note how to handle corner case (where some buildings are not accessible)
Time: O(m^2*n^2)
Space: O(m*n)
m, n = rows, cols
**/

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        //if(grid == NULL) return -1;
        rows = grid.size();
        cols = rows ? grid[0].size() : 0;
        if(!rows || !cols) return -1;
        vector<vector<int>> sums(rows, vector<int>(cols, 0));
        vector<vector<int>> counts(rows, vector<int>(cols, 0));
        vector<pair<int,int>> buildings;
        int slots_num = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1)
                    buildings.push_back(make_pair(i, j));
                else if(grid[i][j] == 0)
                    slots_num++;
            }
        }
        for(auto p: buildings){
            int count = 1;
            unordered_set<int> visited;
            queue<pair<int, int>> q;
            q.push(p);
            //visited.insert(p.first * cols + p.second);
            int dist = 0;
            while(!q.empty()){
                int num = q.size();
                dist++;
                for(int i = 0; i < num; i++){
                    auto cur = q.front();
                    q.pop();
                    counts[cur.first][cur.second]++;
                    for(auto dir: directions){
                        int newY = cur.first + dir.first, newX = cur.second + dir.second;
                        if(valid(grid, visited, newY, newX)){
                            pair<int, int> next = make_pair(newY, newX);
                            q.push(next);
                            visited.insert(newY * cols + newX);
                            sums[newY][newX] += dist;
                        }
                    }
                }
            }
        }
        int result = INT_MAX;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 0 && counts[i][j] == buildings.size()) result = min(result, sums[i][j]);
            }
        }
        return (result == INT_MAX) ? -1 : result;
    }
private:
    vector<pair<int, int>> directions{{0,-1},{0,1},{-1,0},{1,0}};
    int rows;
    int cols;
    bool valid(vector<vector<int>>& grid, unordered_set<int>& visited, int y, int x){
        return (y >= 0 && y < rows && x >= 0 && x < cols) && 
            visited.find(y * cols + x) == visited.end() &&
            grid[y][x] == 0;
    }
};

int main(void){
    vector<vector<int>> map = readMatrix();
    Solution sol;
    int res = sol.shortestDistance(map);
    cout << res << endl;
    return 0;
    return 0;
}
