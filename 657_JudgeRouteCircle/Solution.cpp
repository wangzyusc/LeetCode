#include "../IOLib.hpp"

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(auto c: moves){
            if(c == 'U') y++;
            else if(c == 'D') y--;
            else if(c == 'R') x++;
            else if(c == 'L') x--;
        }
        return (x == 0) && (y == 0);
    }
};

int main(void){
    string move = readString();
    Solution solution;
    bool circle = solution.judgeCircle(move);
    cout << "The route is " << (circle?"":"not ") << "circle" << endl;
    return 0;
}
