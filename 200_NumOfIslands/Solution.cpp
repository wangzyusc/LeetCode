#include "../IOLib.hpp"

class Solution {
private:
    int rows;
    int cols;
public:
    typedef pair<int, int> pos;
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        if(rows == 0) return 0;
        cols = grid[0].size();
        if(cols == 0) return 0;
        vector<vector<int> > map(rows, vector<int>(cols, 0));
        int count = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] != '0' && map[i][j] == 0){
                    stack<pos> line;
                    line.push(make_pair(i, j));
                    count++;
                    while(!line.empty()){
                        auto cur = line.top();
                        line.pop();
                        map[cur.first][cur.second] = count;
                        if(inbound(cur.first-1, cur.second) &&
                          grid[cur.first-1][cur.second] != '0' &&
                          map[cur.first-1][cur.second] == 0)
                            line.push(make_pair(cur.first-1, cur.second));
                        if(inbound(cur.first, cur.second-1) &&
                          grid[cur.first][cur.second-1] != '0' &&
                          map[cur.first][cur.second-1] == 0)
                            line.push(make_pair(cur.first, cur.second-1));
                        if(inbound(cur.first+1, cur.second) &&
                          grid[cur.first+1][cur.second] != '0' &&
                          map[cur.first+1][cur.second] == 0)
                            line.push(make_pair(cur.first+1, cur.second));
                        if(inbound(cur.first, cur.second+1) &&
                          grid[cur.first][cur.second+1] != '0' &&
                          map[cur.first][cur.second+1] == 0)
                            line.push(make_pair(cur.first, cur.second+1));
                    }
                }
            }
        }
        return count;
    }
    bool inbound(int row, int col){
        return (row >= 0 && row < rows && col >= 0 && col < cols);
    }
};
