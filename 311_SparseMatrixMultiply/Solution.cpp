#include "../IOLib.hpp"

class Solution {
public:
    vector<vector<int> > multiply(vector<vector<int> >& A, vector<vector<int> >& B) {
        //assert(A.size() > 0 && A[0].size() > 0 && B.size() > 0 && B[0].size() > 0);
        int rows = A.size(), cols = B[0].size(), depth = B.size();
        vector<vector<int> > result(rows, vector<int>(cols, 0));
        for(int i = 0; i < rows; i++){
            for(int k = 0; k < depth; k++){
                if(A[i][k] == 0) continue;
                int& num = A[i][k];
                for(int j = 0; j < cols; j++){
                    result[i][j] += num * B[k][j];
                }
            }
        }
        return result;
    }
};

int main(void){
    vector<vector<int> > A, B;
    readMatrix(A);
    readMatrix(B);
    Solution solution;
    vector<vector<int> > product = solution.multiply(A, B);
    printMatrix(product);
    return 0;
}
