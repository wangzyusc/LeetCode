#include "../IOLib.hpp"

/***
This is Eulerian path. Greedy DFS, building the route backwards when retreating.
Difficult to understand!! Need to review in the future...
Time: O(m+n)
Space: O(m+n)
***/
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> flights;
        for(auto p: tickets)
            flights[p.first].insert(p.second);
        vector<string> result;
        dfs(flights, result, "JFK");
        reverse(result.begin(), result.end());
        return result;
    }
    void dfs(unordered_map<string, multiset<string>>& flights, vector<string>& result, string cur){
        while(flights[cur].size()){
            string next = *flights[cur].begin();
            flights[cur].erase(flights[cur].begin());
            dfs(flights, result, next);
        }
        result.push_back(cur);
    }
};

int main(void){
    vector<pair<string, string>> tickets = readVector<pair<string, string>>();
    Solution sol;
    vector<string> res = sol.findItinerary(tickets);
    printVector(res);
    return 0;
}
