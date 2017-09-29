#include "../IOLib.hpp"

struct triple{
    int y;
    int x;
    int lvl;
    triple(int i, int j, int c): y(i), x(j), lvl(c) {}
};

class Solution {
public:
    void wallsAndGates(vector<vector<int> >& rooms) {
        rows = rooms.size();
        if(rows == 0) return;
        cols = rooms[0].size();
        if(cols == 0) return;
        queue<triple> line;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(rooms[i][j] == 0){
                    line.push(triple(i, j, 0));
                }
            }
        }
        int bias[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        while(!line.empty()){
            triple p = line.front();
            line.pop();
            if(rooms[p.y][p.x] != INT_MAX &&
               rooms[p.y][p.x] != 0) continue;
            rooms[p.y][p.x] = p.lvl;
            for(int i = 0; i < 4; i++){
                int y = p.y + bias[i][0], x = p.x + bias[i][1];
                if(inbound(y, x) && rooms[y][x] == INT_MAX){
                    line.push(triple(y, x, p.lvl + 1));
                }
            }
        }
    }
    bool inbound(int y, int x){
        return (y >= 0) && (y < rows) && (x >= 0) && (x < cols);
    }
private:
    int rows;
    int cols;
};

int main(void){
    return 0;
}
