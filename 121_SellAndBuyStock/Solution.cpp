#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int profit = 0;
    int len = prices.size();
    if(len == 0) return profit;
    int min = prices[0];
    for(int i = 1; i < len; i++){
      if(prices[i] < min){
	min = prices[i];
	continue;
      }
      if(prices[i] > min)
	profit = max(profit, prices[i] - min);
    }
    return profit;
  }
};

int main(void){
  vector<int> prices;
  readVector(prices);
  Solution solution;
  int profit = solution.maxProfit(prices);
  cout << "Max profit is " << profit << endl;
  return 0;
}
