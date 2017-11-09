#include "../IOLib.hpp"

/***
Still use Union-Find, but the logic is different.
Step1: Find if two parents share one child. If so, invalid the second one.
Step2: Find if the graph has cycle, if it doesn't, return second edge in step 1;
       else (it has cycle), if there's no match in step1, return current edge that
       makes the cycle, else return first candidate in step#1 (why?).
Time: O(n*Alpha(n))
Space: O(n)
***/
class Solution {
private:
    vector<int> parent;
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        parent = vector<int>(edges.size() + 1, 0);
        vector<int> cand1, cand2;
        for(auto& e: edges){
            if(parent[e[1]] != 0){
                cand1 = {parent[e[1]], e[1]};
                cand2 = e;
                e[1] = 0;
            }
            parent[e[1]] = e[0];
        }
        //Union-find
        for(int i = 0; i < parent.size(); i++)
            parent[i] = i;
        for(auto e: edges){
            int i = find(e[0]), j = e[1];
            if(i == j){
                if(cand1.empty()) return e;
                else return cand1;
            }
            parent[e[1]] = e[0];
        }
        return cand2;
    }
    int find(int idx){
        while(idx != parent[idx])
            idx = parent[idx];
        return idx;
    }
};

