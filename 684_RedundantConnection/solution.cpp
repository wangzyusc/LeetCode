#include "../IOLib.hpp"

class Solution {
private:
    vector<int> id;
    vector<int> sz;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        id = vector<int>(edges.size() + 1, 0);
        sz = vector<int>(edges.size() + 1, 1);
        for(int i = 0; i < id.size(); i++)
            id[i] = i;
        for(auto e: edges){
            int i = find(e[0]), j = find(e[1]);
            cout << i << ", " << j << endl;
            if(i != j)
                Union(i, j);
            else return e;
        }
        return vector<int>(0,0);
    }
    int find(int idx){
        while(id[idx] != idx){
            idx = id[idx];
        }
        return idx;
    }
    void Union(int i, int j){
        if(sz[i] < sz[j]){
            id[i] = j;
            sz[j] += sz[i];
        }
        else{
            id[j] = i;
            sz[i] += sz[j];
        }
    }
};

int main(void){
    vector<vector<int>> edges = readMatrix();
    Solution sol;
    vector<int> result = sol.findRedundantConnection(edges);
    printVector(result);
    return 0;
}
