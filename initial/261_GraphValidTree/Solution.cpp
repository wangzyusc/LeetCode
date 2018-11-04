#include "../IOLib.hpp"

class Solution {
public:
    bool validTree(int n, vector<pair<int, int> >& edges) {
        if(n <= 1) return true;
        if(n - 1 != edges.size()) return false;
        vector<unordered_set<int> > neighbor(n);
        vector<int> degree(n);
        for(const auto& p: edges){
            neighbor[p.first].insert(p.second);
            neighbor[p.second].insert(p.first);
            degree[p.first]++;
            degree[p.second]++;
        }
        queue<int> line;
        for(int i = 0; i < n; i++){
            if(degree[i] == 0) return false;
            if(degree[i] == 1) line.push(i);
        }
        int count = 0;
        while(!line.empty()){
            int cur = line.front();
            line.pop();
            count++;
            for(auto it = neighbor[cur].begin(); it != neighbor[cur].end(); it++){
                degree[*it]--;
                if(degree[*it] == 1){
                    line.push(*it);
                }
            }
        }
        return count == n;
    }
};

int main(void){
    int n = 5;
    vector<pair<int, int> > edges(4);
    edges[0] = make_pair(0, 1);
    edges[1] = make_pair(0, 2);
    edges[2] = make_pair(2, 3);
    edges[3] = make_pair(2, 4);
    Solution sol;
    cout << (sol.validTree(n, edges) ? "true" : "false") << endl;
    return 0;
}
