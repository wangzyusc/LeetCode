#include "../IOLib.hpp"

/***
2D Binary Indexed Tree.
Constructor: O(m*n*log(m)*log(n))
update: O(log(m)*log(n))
sumRegion: O(log(m)*log(n))
Space: O(m * n)
***/

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        rows = matrix.size();
        cols = (rows == 0) ? 0 : matrix[0].size();
        if(rows == 0 || cols == 0) return;
        nums = vector<vector<int>>(rows, vector<int>(cols, 0));
        tree = vector<vector<int>>(rows+1, vector<int>(cols+1, 0));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                update(i, j, matrix[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        int diff = val - nums[row][col];
        nums[row][col] = val;
        row++; col++;
        while(row <= rows){
            int _col = col;
            while(_col <= cols){
                tree[row][_col] += diff;
                _col += (_col & -_col);
            }
            row += (row & -row);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = 0, left = 0, top = 0, intersection = 0;
        total = region(row2, col2);
        if(row1 > 0) top = region(row1 - 1, col2);
        if(col1 > 0) left = region(row2, col1 - 1);
        if(row1 > 0 && col1 > 0) intersection = region(row1 - 1, col1 - 1);
        return total - left - top + intersection;
    }
private:
    vector<vector<int>> nums;
    vector<vector<int>> tree;
    int rows;
    int cols;
    int region(int row, int col){
        int sum = 0;
        row++; col++;
        while(row > 0){
            int _col = col;
            while(_col > 0){
                sum += tree[row][_col];
                _col -= (_col & -_col);
            }
            row -= (row & -row);
        }
        return sum;
    }    
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */

int main(void){
    vector<vector<int>> mat;
    readMatrix(mat);
    NumMatrix obj(mat);
    int res = obj.sumRegion(2,1,4,3);
    cout << "res = " << res << endl;
    return 0;
}
