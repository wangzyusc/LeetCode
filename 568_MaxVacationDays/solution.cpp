#include "../IOLib.hpp"

/**
Forward propagation, have to keep a "set" of possible cities.
But Backward propagation would save the "set".
**/

class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int N = days.size(), K = days[0].size();
        vector<vector<int>> vacations(N, vector<int>(K + 1, 0));
        unordered_set<int> prepos{0};
        unordered_set<int> curpos;
        //transform neighbor matrix to neighbor list
        vector<vector<int>> next(N);
        for(int prev = 0; prev < N; prev++){
            for(int cur = 0; cur < N; cur++){
                if(flights[prev][cur] == 1)
                    next[prev].push_back(cur);
            }
        }
        for(int k = 1; k <= K; k++){
            for(auto it: prepos){
                curpos.insert(it);
                for(auto val: next[it])
                    curpos.insert(val);
            }
            for(int n: curpos){
                int time = vacations[n][k-1];
                for(int prev: prepos){
                    if(flights[prev][n] == 1){
                        time = max(time, vacations[prev][k-1]);
                    }
                }
                vacations[n][k] = time + days[n][k-1];
            }
            prepos = curpos;
            curpos.clear();
        }
        int res = 0;
        for(int n: prepos){
            res = max(vacations[n][K], res);
        }
        return res;
    }
};

int main(void){
    cout << "Flights:" << endl;
    auto flights = readMatrix();
    cout << "Days:" << endl;
    auto days = readMatrix();
    Solution sol;
    int res = sol.maxVacationDays(flights, days);
    cout << "res = " << res << endl;
    return 0;
}
