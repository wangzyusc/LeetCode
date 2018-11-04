#include "../IOLib.hpp"

/***
My own original code.
Use DFS to generate all the abbreviations, and use BFS to generate shortest possible
abbreviations for target string. But it would be TLE for large inputs.
***/
class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        unordered_set<string> abbrs;
        for(auto str: dictionary)
            getAbbrs(abbrs, str, "", 0);
        queue<pair<string, int>> q;
        q.push({"", 0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            if(p.second == target.size()){
                if(abbrs.count(p.first) == 0) return p.first;
                else continue;
            }
            if(p.second == 0 || !isdigit(p.first[p.first.length()-1]))
                for(int i = target.size() - p.second; i >= 1; i--)
                    q.push({p.first + to_string(i), p.second + i});
            q.push({p.first + target[p.second], p.second + 1});
        }
        return target;
    }
    void getAbbrs(unordered_set<string>& abbrs, string& str, string cur, int pos){
        if(pos == str.size()){
            abbrs.insert(cur);
            return;
        }
        getAbbrs(abbrs, str, cur + str[pos], pos + 1);
        if(pos == 0 || !isdigit(cur[cur.size()-1]))
            for(int i = 1; i <= str.size() - pos; i++)
                getAbbrs(abbrs, str, cur + to_string(i), pos + i);
    }
};

/***
Another solution is generate all the possible non-abbreviate positions by using
bit-mask. And also DFS (didn't really understood)
***/

int main(void){
    string target = readString();
    vector<string> dictionary = readVector<string>();
    Solution sol;
    string res = sol.minAbbreviation(target, dictionary);
    cout << res << endl;
    return 0;
}
