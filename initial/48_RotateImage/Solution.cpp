#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int> >& matrix) {
    int n = matrix.size();
    for(int i = 0; i < n; i++){
      for(int j = i + 1; j < n; j++){
	int tmp = matrix[i][j];
	matrix[i][j] = matrix[j][i];
	matrix[j][i] = tmp;
      }
    }
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n/2; j++){
	int tmp = matrix[i][j];
	matrix[i][j] = matrix[i][n-1-j];
	matrix[i][n-1-j] = tmp;
      }
    }
  }
};

int main(){
    vector<vector<int> > matrix;
    readMatrix(matrix);
    Solution solution;
    solution.rotate(matrix);
    printMatrix(matrix);
    return 0;
}
