#include "../IOLib.hpp"

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.empty()) return 0;
        int hold = -prices[0], unhold = 0;
        for(auto& p: prices){
            hold = max(hold, unhold - p);
            unhold = max(unhold, hold + p - fee);
        }
        return max(hold, unhold);
    }
};

int main(void){
    vector<int> prices = readVector<int>();
    int fee = readInt();
    Solution sol;
    int result = sol.maxProfit(prices, fee);
    cout << "max profit is " << result << endl;
    return 0;
}
