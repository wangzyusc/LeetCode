#include "../IOLib.hpp"

class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> skip(10, vector<int>(10, 0));
        vector<bool> path(10, false);
        path[0] = true;
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[7][9] = skip[9][7] = 8;
        skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5;
        int res = dfs(skip, path, m, n, 1, 1) * 4;
        res += dfs(skip, path, m, n, 2, 1) * 4;
        res += dfs(skip, path, m, n, 5, 1);
        return res;
    }
    int dfs(vector<vector<int>>& skip, vector<bool>& path, int& m, int& n, int pos, int count){
        int result = 0;
        if(count == n) return 1;
        if(count >= m) result += 1;
        path[pos] = true;
        for(int i = 1; i < 10; i++){
            if(path[i]) continue;
            if(!path[skip[pos][i]]) continue;
            result += dfs(skip, path, m, n, i, count+1);
        }
        path[pos] = false;
        return result;
    }
};

int main(void){
    int m = readInt();
    int n = readInt();
    Solution sol;
    int res = sol.numberOfPatterns(m,n);
    cout << "res = " << res << endl;
    return 0;
}
