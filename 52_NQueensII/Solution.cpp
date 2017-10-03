#include "../IOLib.hpp"

class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> filled(5*n-2, false);
        vector<int> pos;
        int sum = 0;
        solver(pos, filled, sum, n);
        return sum;
    }
    void solver(vector<int>& pos, vector<bool>& filled, int& sum, int n){
        if(pos.size() == n) sum++;
        int row = pos.size();
        for(int col = 0; col < n; col++){
            if(filled[col] || filled[n + row + col] || filled[4*n-2+row-col])
                continue;
            pos.push_back(col);
            filled[col] = true;
            filled[n+row+col] = true;
            filled[4*n-2+row-col] = true;
            solver(pos, filled, sum, n);
            pos.pop_back();
            filled[col] = false;
            filled[n+row+col] = false;
            filled[4*n-2+row-col] = false;
        }
    }
};

int main(void){
    int n = readInt();
    Solution sol;
    cout << sol.totalNQueens(n) << endl;
    return 0;
}
