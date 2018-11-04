#include "../IOLib.hpp"

/***
Solution 1. My own original solution, but not optimal.
Uses priority queue, but include all (m*n) possible pairs.
Time: O(mn*log(mn))
Space: O(mn)
***/
class cmp{
public:
    bool operator()(pair<int,int>& a, pair<int,int>& b){
        return a.first+a.second > b.first+b.second;
    }
};
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for(auto a: nums1){
            for(auto b: nums2){
                pq.push(make_pair(a, b));
            }
        }
        vector<pair<int, int>> result;
        while(!pq.empty() && result.size() < k){
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};

/***
Solution 2. Improve on priority queue, save indices pair instead. Each time take the smallest one
out from pq, and insert two "neighbor" pairs into pq.
Time: O(K*log(K)), K = min(k, m*n)
Space: O(K)
***/
/***
Note the use of lambda function and declaration of pq here!
auto cmp = [&...](){};
pq<..., ..., decltype(cmp)> pq(cmp);
***/
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> result;
        if(nums1.empty() || nums2.empty()) return result;
        auto cmp = [&nums1, &nums2](pair<int,int>& a, pair<int,int>& b){
            return nums1[a.first]+nums2[a.second] > nums1[b.first]+nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        pq.push(make_pair(0,0));
        while(!pq.empty() && result.size() < k){
            auto p = pq.top();
            pq.pop();
            result.push_back(make_pair(nums1[p.first], nums2[p.second]));
            if(p.first + 1 < nums1.size())
                pq.push(make_pair(p.first+1, p.second));
            if(p.first == 0 && p.second + 1 < nums2.size())
                pq.push(make_pair(p.first, p.second + 1));
        }
        return result;
    }
};
