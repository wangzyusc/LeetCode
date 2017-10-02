#include "../IOLib.hpp"

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<int, unordered_set<int>> graph;
        vector<bool> dict(26, false);
        for(auto word: words){
            for(auto ch: word){
                dict[ch - 'a'] = true;
            }
        }
        for(int i = 0; i < words.size() - 1; i++){
            for(int j = i+1; j < words.size(); j++){
                int k = 0, len = min(words[i].size(), words[j].size());
                while(k < len && words[i][k] == words[j][k]){
                    k++;
                }
                if(k < len &&
                   graph[words[i][k]-'a'].find(words[j][k]-'a') == graph[words[i][k]-'a'].end())
                    graph[words[i][k]-'a'].insert(words[j][k]-'a');
            }
        }
        vector<char> result;
        vector<bool> explored(26, false);
        vector<bool> onpath(26, false);
        for(int i = 0; i < 26; i++){
            if(dict[i])
                if(dfs(graph, explored, onpath, result, i)) return "";
        }
        reverse(result.begin(), result.end());
        string res(result.size(), 'a');
        for(int i = 0; i < result.size(); i++){
            res[i] = result[i];
        }
        return res;
    }
    bool dfs(unordered_map<int, unordered_set<int>>& graph,
             vector<bool>& explored,
             vector<bool>& onpath,
             vector<char>& result,
             int c){
        if(explored[c]) return false;
        explored[c] = true;
        onpath[c] = true;
        for(auto it = graph[c].begin(); it != graph[c].end(); it++){
            if(onpath[*it] || dfs(graph, explored, onpath, result, *it))
                return true;
        }
        result.push_back(c+'a');
        onpath[c] = false;
        return false;
    }
};

int main(void){
    return 0;
}
