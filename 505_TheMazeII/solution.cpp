#include "../IOLib.hpp"

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int rows = maze.size(), cols = maze[0].size();
        vector<vector<int>> distance(rows, vector<int>(cols, -1));
        vector<vector<int>> directions{{0,-1},{0,1},{-1,0},{1,0}};
        queue<pair<int,int>> q;
        q.push(make_pair(start[0], start[1]));
        distance[start[0]][start[1]] = 0;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            if(p.first == destination[0] && p.second == destination[1]) continue;
            for(auto d: directions){
                auto temp = p;
                int y = temp.first, x = temp.second, dist = 0;
                while((y + d[0] >= 0) && (y + d[0] < rows) && (x + d[1] >= 0) && (x + d[1] < cols)
                      && (maze[y+d[0]][x+d[1]] == 0)){
                    y += d[0];
                    x += d[1];
                    dist++;
                }
                if(distance[y][x] == -1 || distance[y][x] > distance[temp.first][temp.second] + dist){
                    distance[y][x] = distance[temp.first][temp.second] + dist;
                    q.push(make_pair(y, x));
                }
            }
        }
        return distance[destination[0]][destination[1]];
    }
};

int main(void){
    vector<vector<int>> maze = readMatrix();
    vector<int> start = readVector<int>();
    vector<int> dst = readVector<int>();
    Solution sol;
    int res = sol.shortestDistance(maze, start, dst);
    cout << "Res = " << res << endl;
    return 0;
}
