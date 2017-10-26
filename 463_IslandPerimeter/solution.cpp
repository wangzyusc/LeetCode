#include "../IOLib.hpp"

/***
DFS.
Time: O(mn)
Space: O(mn)
***/
class Solution {
    vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
    int rows;
    int cols;
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        rows = grid.size(), cols = grid[0].size();
        vector<int> counter(5, 0);
        unordered_set<int> visited;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j]){
                    dfs(grid, visited, i, j, counter);
                    int sum = 0;
                    for(int i = 1; i < 5; i++){
                        sum += i * counter[i];
                    }
                    return sum;
                }
            }
        }
        return 0;
    }
    void dfs(vector<vector<int>>& grid, unordered_set<int>& visited, int i, int j, vector<int>& counter){
        int id = i * cols + j;
        if(visited.find(id) != visited.end()) return;
        visited.insert(id);
        int count = 0;
        for(auto dir: directions){
            int y = i + dir[0], x = j + dir[1];
            if(y >= 0 && y < rows && x >= 0 && x < cols && grid[y][x])
                dfs(grid, visited, y, x, counter);
            else count++;
        }
        counter[count]++;
    }
};

/***
Faster way.
Time: O(mn)
Space: O(1)
***/

class Solution {
    vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
    int rows;
    int cols;
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        rows = grid.size(), cols = grid[0].size();
        int total = 0, neighbor = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j]){
                    total++;
                    if(i > 0 && grid[i-1][j]) neighbor++;
                    if(j > 0 && grid[i][j-1]) neighbor++;
                }
            }
        }
        return total * 4 - neighbor * 2;
    } 
};
