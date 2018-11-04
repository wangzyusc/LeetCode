#include "../IOLib.hpp"

/***
Union-Find.
1. Find parent.
2. Size Compare.
3. Path Compression (grand-parent).
Time: O(k*log(k)) <= O(k*log(m*n))
Space: O(k)
***/

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        rows = m; cols = n;
        vector<int> result;
        for(auto p: positions){
            int idx = p.first * cols + p.second;
            id[idx] = idx;
            size[idx] = 1;
            count++;
            int nidx;
            if(p.first > 0 &&
               id.find((nidx = (p.first - 1) * cols + p.second)) != id.end()){
                Union(idx, nidx);
            }
            if(p.first < (rows - 1) &&
               id.find((nidx = (p.first + 1) * cols + p.second)) != id.end()){
                Union(idx, nidx);
            }
            if(p.second > 0 &&
               id.find((nidx = p.first * cols + p.second - 1)) != id.end()){
                Union(idx, nidx);
            }
            if(p.second < (cols - 1) &&
               id.find((nidx = p.first * cols + p.second + 1)) != id.end()){
                Union(idx, nidx);
            }
            result.push_back(count);
        }
        return result;
    }
private:
    int find(int p){
        while(p != id[p]){
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }
    void Union(int p, int q){
        int i = find(p);
        int j = find(q);
        if(i == j) return;
        if(size[i] < size[j]){
            id[i] = j;
            size[j] += size[i];
        }
        else{
            id[j] = i;
            size[i] += size[j];
        }
        count--;
    }
private:
    int rows;
    int cols;
    unordered_map<int, int> id;
    unordered_map<int, int> size;
    int count = 0;
};
