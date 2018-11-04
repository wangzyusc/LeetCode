#include "../IOLib.hpp"

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> pre;
        helper(result, pre, 1, n, k);
        return result;
    }
    
    void helper(vector<vector<int> > &result, vector<int> &pre, int start, int end, int k){
        if(k == 0){
            result.push_back(pre);
            return;
        }
        if(start > end || end - start + 1 < k) return;
        helper(result, pre, start + 1, end, k);
        pre.push_back(start);
        helper(result, pre, start + 1, end, k - 1);
        pre.pop_back();
    }
};

int main(void){
    cout << "n: ";
    int n = readInt();
    cout << "k: ";
    int k = readInt();
    Solution solution;
    vector<vector<int> > res = solution.combine(n, k);
    printMatrix(res);
    return 0;
}
