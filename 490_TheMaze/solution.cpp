#include "../IOLib.hpp"

/***
BFS.
Time: O(mn)
Space: O(mn)
Could also use DFS with same time / space complexity.
***/

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int rows = maze.size(), cols = maze[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<vector<int>> directions{{0,-1},{0,1},{-1,0},{1,0}};
        queue<pair<int,int>> q;
        q.push(make_pair(start[0], start[1]));
        visited[start[0]][start[1]] = true;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            if(p.first == destination[0] && p.second == destination[1]) return true;
            visited[p.first][p.second] = true;
            for(auto d: directions){
                auto temp = p;
                int y = temp.first, x = temp.second;
                while((y + d[0] >= 0) && (y + d[0] < rows) && (x + d[1] >= 0) && (x + d[1] < cols)
                      && (maze[y+d[0]][x+d[1]] == 0)){
                    y += d[0];
                    x += d[1];
                }
                if(!visited[y][x]){
                    q.push(make_pair(y, x));
                    visited[y][x] = true;
                }
            }
        }
        return false;
    }
};
