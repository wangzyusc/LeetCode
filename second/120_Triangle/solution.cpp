#include "../../IOLib.hpp"

/**
 * Trivial solution. Top-down approach. Each path would be traversed once.
 * Time complexity: O(2^n)
 * Space complexity: O(n)
 */

class Solution1 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int len = triangle.size();
        if(len == 0) return 0;
        long res = LONG_MAX;
        traverse(triangle, 0, 0, 0, res, len);
        return (int)res;
    }
    void traverse(vector<vector<int>>& t,
                  int level,
                  int cur_index,
                  long sum,
                  long& res,
                  int& len) {
        if(level == len){
            res = min(res, sum);
            return;
        }
        sum += t[level][cur_index];
        ++level;
        traverse(t, level, cur_index, sum, res, len);
        traverse(t, level, cur_index + 1, sum, res, len);
    }
};

/**
 * DP solution. Elimiate duplicate visits to bottom elements.
 * Each element in the triangle only gets visited once.
 * Time complexity: O(# of elements) = O(n^2)
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int len = triangle.size();
        if(len == 0) return 0;
        for(int i = len - 2; i >= 0; --i) {
            for(int j = 0; j < triangle[i].size(); ++j) {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};
