#include "../IOLib.hpp"

/**
BFS. Use candidate squares as candidates, do BFS. (like combination sum)
Time: O((√n)^(√n))
Space: O((√n)^(√n))
**/

class Solution {
public:
    int numSquares(int n) {
        vector<int> elements;
        int i = 1, square;
        while((square = i * i) <= n){
            if(square == n) return 1;
            else elements.push_back(square);
            i++;
        }
        unordered_set<int> checked;
        queue<int> q;
        q.push(n);
        checked.insert(n);
        int depth = 0;
        while(!q.empty()){
            int k = q.size();
            depth++;
            for(int i = 0; i < k; i++){
                int cur = q.front();
                q.pop();
                for(int diff: elements){
                    if(cur == diff) return depth;
                    if(cur < diff) break;
                    int next = cur - diff;
                    if(checked.find(next) == checked.end()){
                        q.push(next);
                        checked.insert(next);
                    }
                }
            }
        }
        return -1;
    }
};

/**
DP. dp[i] is the least number of perfect square numbers sum up to i.
Time: O(n)
Space: O(n)
**/
class Solution {
public:
    int numSquares(int n) {
        while((n & 3) == 0) n >>= 2;
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i <= n; i++){
            for(int j = 1; j * j <= i; j++){
                dp[i] = min(dp[i], dp[i-j*j] + 1);
            }
        }
        return dp.back();
    }
};

/**
Magic...
Time: O(√n)
Space: O(1)
**/
class Solution {
public:
    int numSquares(int n) {
        while(n % 4 == 0) n /= 4;
        if(n % 8 == 7) return 4;
        for(int a = 0; a * a <= n; a++){
            int b = sqrt(n - a * a);
            if(a * a + b * b == n){
                return !!a + !!b;
            }
        }
        return 3;
    }
};
