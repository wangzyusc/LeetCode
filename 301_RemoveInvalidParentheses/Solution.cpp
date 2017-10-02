#include "../IOLib.hpp"

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_map<string, int> dict;
        queue<string> q;
        int least = s.size() + 1;
        dict[s] = 1;
        q.push(s);
        while(!q.empty()){
            string cur = q.front();
            q.pop();
            if(dict[cur] > least) break;
            if(valid(cur)){
                result.push_back(cur);
                least = dict[cur];
            }
            if(dict[cur] == least) continue;
            for(int i = 0; i < cur.size(); i++){
                if(cur[i] == '(' || cur[i] == ')'){
                    string next = cur.substr(0, i) + cur.substr(i+1);
                    if(dict.find(next) != dict.end()) continue;
                    q.push(next);
                    dict[next] = dict[cur] + 1;
                }
            }
        }
        return result;
    }
    bool valid(string s){
        int count = 0;
        for(auto c: s){
            if(c == '(') count++;
            else if(c == ')') count--;
            if(count < 0) return false;
        }
        return count == 0;
    }
};

int main(void){
    string s = readString();
    Solution sol;
    vector<string> strs = sol.removeInvalidParentheses(s);
    cout << "[";
    for(auto str: strs){
        cout << " \"" << str << "\"," << endl;
    }
    cout << "]" << endl;
    return 0;
}
