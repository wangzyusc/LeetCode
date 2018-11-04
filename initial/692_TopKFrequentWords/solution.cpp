#include "../IOLib.hpp"

/* Use hashmap and hashset */
/* Time: O(n) + O(n) + O(k * log(n)) = O(n * log(n)),
 * Space: O(n)
 */
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counts;
        for(auto& str: words)
            counts[str]++;
        map<int, set<string>> hash;
        for(auto& p: counts)
            hash[p.second].insert(p.first);
        vector<string> result;
        for(auto it = hash.rbegin();
            result.size() < k && it != hash.rend();
            it++){
            for(auto it2 = it->second.begin();
                result.size() < k && it2 != it->second.end();
                it2++){
                result.push_back(*it2);
            }
        }
        return result;
    }
};

/* Should use priority queue / heap for this problem,
 * remember the method of using heap when faced with top K
 * elements problem.
 */
class Solution2 {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counts;
        for(auto& str: words)
            counts[str]++;
        auto comparator = [](pair<int, string>& a, pair<int, string>& b){
            if(a.first != b.first) return a.first > b.first;
            else return a.second < b.second;
        };
        /* Priority queue implementation is min-heap, i.e. by default the
         * comparator is less<T, T>, then top() would return largest one.
         * If comparator is greater<T, T>, then top() would return smallest
         * one. In other words, it return the opposite direction of elements
         * against the definition of comparator.
         */
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comparator)> pq(comparator);
        for(auto& p: counts){
            pq.push(make_pair(p.second, p.first));
            if(pq.size() > k) pq.pop();
        }
        vector<string> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
