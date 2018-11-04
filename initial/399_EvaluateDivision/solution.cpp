#include "../IOLib.hpp"

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        for(int i = 0; i < equations.size(); i++){
            pair<string, string>& p = equations[i];
            graph[p.first][p.second] = values[i];
            graph[p.second][p.first] = 1 / values[i];
        }
        vector<double> result;
        unordered_map<string, bool> visited;
        for(auto it: graph) visited[it.first] = false;
        for(auto & p: queries){
            result.push_back(dfs(graph, visited, p.first, p.second));
        }
        return result;
    }
    double dfs(unordered_map<string, unordered_map<string, double>>& graph, unordered_map<string, bool>& visited, string src, string& dst){
        if(visited.find(src) == visited.end() || visited.find(dst) == visited.end()) return -1;
        if(visited[src] == true) return -1;
        double result = 1;
        if(src == dst) return result;
        result = -1;
        visited[src] = true;
        for(auto it: graph[src]){
            double factor = dfs(graph, visited, it.first, dst);
            if(factor != -1){
                result = factor * graph[src][it.first];
                break;
            }
        }
        visited[src] = false;
        return result;
    }
};

int main(void){
    vector<pair<string, string>> equations = readVector<pair<string, string>>();
    vector<double> values = readVector<double>();
    vector<pair<string, string>> queries = readVector<pair<string, string>>();
    Solution sol;
    vector<double> res = sol.calcEquation(equations, values, queries);
    printVector(res);
    return 0;
}
