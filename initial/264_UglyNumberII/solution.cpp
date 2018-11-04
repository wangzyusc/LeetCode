#include "../IOLib.hpp"

/**
Easy solution with heap and map, but really slow.
Time: O(n)
Space: O(n)
**/
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> cand;
        unordered_set<long> history;
        int i = 0;
        cand.push(1);
        history.insert(1);
        while(i < n){
            long cur = cand.top();
            cand.pop();
            if(++i == n) return cur;
            if(history.find(cur * 2) == history.end()) cand.push(cur * 2);
            if(history.find(cur * 3) == history.end()) cand.push(cur * 3);
            if(history.find(cur * 5) == history.end()) cand.push(cur * 5);
            history.insert(cur * 2);
            history.insert(cur * 3);
            history.insert(cur * 5);
        }
    }
};

/**
Much better solution.
Time: O(n)
Space: O(n)
**/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums(n, 1);
        int i = 0, j = 0, k = 0;
        for(int cur = 1; cur < n; cur++){
            int cand2 = nums[i] * 2;
            int cand3 = nums[j] * 3;
            int cand5 = nums[k] * 5;
            int cand = min(cand2, min(cand3, cand5));
            nums[cur] = cand;
            if(cand2 == cand) i++;
            if(cand3 == cand) j++;
            if(cand5 == cand) k++;
        }
        return nums[n-1];
    }
};
