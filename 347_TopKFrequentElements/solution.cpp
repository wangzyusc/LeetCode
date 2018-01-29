#include "../IOLib.hpp"

/* Use hashmap to keep counts, heap to find top k elements.
 * Time: O(n * log(k)), space: O(n)
 * There's another solution: bucket sort in O(n) time.
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for(auto n: nums)
            counts[n]++;
        auto comp = [](pair<int, int>& a, pair<int, int>& b){
            return a.second > b.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        for(auto p: counts){
            if(pq.size() < k)
                pq.push(p);
            else if(pq.top().second < p.second){
                pq.pop();
                pq.push(p);
            }
        }
        vector<int> result(k);
        int index = k - 1;
        while(!pq.empty()){
            auto temp = pq.top();
            result[index--] = temp.first;
            pq.pop();
        }
        return result;
    }
};
