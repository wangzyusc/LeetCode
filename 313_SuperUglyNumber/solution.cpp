#include "../IOLib.hpp"

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size(); 
        vector<int> nums(n, INT_MAX);
        nums[0] = 1;
        vector<int> idx(k, 0);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < k; j++){
                int cur = nums[idx[j]] * primes[j];
                nums[i] = min(nums[i], cur);
            }
            for(int j = 0; j < k; j++){
                if(nums[idx[j]] * primes[j] == nums[i])
                    idx[j]++;
            }
        }
        return nums.back();
    }
};

int main(void){
    int n = readInt();
    vector<int> primes;
    readVector(primes);
    Solution sol;
    int res = sol.nthSuperUglyNumber(n, primes);
    cout << res << endl;
    return 0;
}
