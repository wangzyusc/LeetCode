#include "../IOLib.hpp"

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<vector<int> > next(numCourses);
        for(auto p: prerequisites){
            next[p.second].push_back(p.first);
        }
        vector<bool> explored(numCourses, false);
        vector<bool> onpath(numCourses, false);
        vector<int> result;
        int idx = numCourses - 1;
        for(int i = 0; i < numCourses; i++){
            if(!explored[i] && dfs(explored, onpath, next, result, i)){
                return {};
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
    bool dfs(vector<bool>& explored, vector<bool>& path,
             const vector<vector<int> >& next,
             vector<int>& result, int num){
        if(explored[num]) return false;
        explored[num] = true;
        path[num] = true;
        for(auto pos: next[num]){
            if(path[pos] || dfs(explored, path, next, result, pos)){
                return true;
            }
        }
        result.push_back(num);
        path[num] = false;
        return false;
    }
};

int main(void){
    vector<pair<int, int> > pre;
    pre.push_back(make_pair(1, 0));
    Solution sol;
    auto res = sol.findOrder(2, pre);
    printVector(res);
    return 0;
}
