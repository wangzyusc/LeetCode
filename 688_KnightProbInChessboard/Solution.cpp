#include "../IOLib.hpp"

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        //moves = vector<vector<int> >(8, vector<int>(2, 0));
        vector<vector<int> > _moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
        moves = _moves;
        _N = N; _K = K;
        prob = 0.125;
        sum = 0;
        dfs(r, c, 0);
        return sum;
    }
    void dfs(int r, int c, int K){
        if(onboard(r, c)){
            if(K == _K){
                sum += pow(prob, K);
            }
            else{
                for(int i = 0; i < 8; i++){
                    dfs(r + moves[i][0], c + moves[i][1], K + 1);
                }
            }
        }
    }
private:
    bool onboard(int r, int c){
        return (r >= 0) && (r < _N) && (c >= 0) && (c < _N);
    }
private:
    int _N;
    int _K;
    double prob;
    double sum;
    vector<vector<int> > moves;
};

int main(void){
    Solution sol;
    cout << sol.knightProbability(3, 2, 0, 0) << endl;
    return 0;
}
