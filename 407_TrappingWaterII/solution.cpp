#include "../IOLib.hpp"

class Solution {
    struct slot{
        int y, x, h;
        slot(int _y, int _x, int _h):y(_y), x(_x), h(_h){}
    };
    class cmp{
    public:
        bool operator()(slot& a, slot& b){
            return a.h > b.h;
        }
    };
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.empty()) return 0;
        int rows = heightMap.size(), cols = heightMap[0].size();
        priority_queue<slot, vector<slot>, cmp> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int i = 0; i < rows; i++){
            visited[i][0] = visited[i][cols - 1] = true;
            q.push(slot(i, 0, heightMap[i][0]));
            q.push(slot(i, cols - 1, heightMap[i][cols-1]));
        }
        for(int i = 1; i < cols - 1; i++){
            visited[0][i] = visited[rows-1][i] = true;
            q.push(slot(0, i, heightMap[0][i]));
            q.push(slot(rows-1, i, heightMap[rows-1][i]));
        }
        vector<pair<int, int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
        int water = 0;
        while(!q.empty()){
            slot cur = q.top();
            q.pop();
            for(auto dir: directions){
                int y = cur.y + dir.first, x = cur.x + dir.second;
                if(y >= 0 && y < rows && x >= 0 && x < cols && (visited[y][x] == false)){
                    water += max(0, cur.h - heightMap[y][x]);
                    q.push(slot(y, x, max(heightMap[y][x], cur.h)));
                    visited[y][x] = true;
                }
            }
        }
        return water;
    }
};

int main(void){
    cout << "Input height map:" << endl;
    vector<vector<int>> heightmap = readMatrix();
    Solution sol;
    int res = sol.trapRainWater(heightmap);
    cout << "res = " << res << endl;
    return 0;
}
