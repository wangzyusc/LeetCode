#include "../IOLib.hpp"

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(tasks.size() == 0 || n == 0) return tasks.size();
        int longest = 0;
        unordered_map<char, int> dict;
        for(auto c: tasks){
            dict[c]++;
            if(dict[c] > longest) longest = dict[c];
        }
        int ans = (n + 1) * (longest - 1);
        for(auto it = dict.begin(); it != dict.end(); it++){
            if(it->second == longest) ans++;
        }
        return max(ans, (int)tasks.size());
    }
};
