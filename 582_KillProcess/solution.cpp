#include "../IOLib.hpp"

/* Hashmap + DFS */
/* Time: O(n), Space: O(n) */
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> child;
        for(int i = 0; i < pid.size(); i++){
            child[ppid[i]].push_back(pid[i]);
        }
        vector<int> result;
        addChildren(child, result, kill);
        return result;
    }
    void addChildren(unordered_map<int, vector<int>>& child, vector<int>& result, int kill){
        result.push_back(kill);
        if(child.find(kill) != child.end())
            for(auto id: child[kill])
                addChildren(child, result, id);
    }
};

/* Another solution is Hashmap + BFS with same time and space complexity */
