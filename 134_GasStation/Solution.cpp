#include "../IOLib.hpp"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sz = gas.size();
        vector<int> more(sz, 0);
        for(int i = 0; i < sz; i++){
            more[i] = gas[i] - cost[i];
        }
        int i = 0;
        while(i < sz){
            if(more[i] < 0){
                i++;
                continue;
            }
            int sum = 0, p = i;
            while(sum >= 0 && p < i + sz){
                sum += more[p % sz];
                p++;
            }
            if(p == i + sz){//finished round
                if(sum >= 0) return i;
                else break;
            }
            i = p;
        }
        return -1;
    }
};

int main(void){
    vector<int> gas, cost;
    readVector(gas);
    readVector(cost);
    Solution sol;
    cout << sol.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
