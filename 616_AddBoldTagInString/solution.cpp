#include "../IOLib.hpp"

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        string result;
        string open = "<b>", close = "</b>";
        unordered_map<int, unordered_set<string>> words;
        for(string& d: dict){
            words[d.size()].insert(d);
        }
        vector<pair<int, int>> positions = merge(find(s, words));
        int last = 0;
        for(auto pos: positions){
            result += (s.substr(last, pos.first - last) + open + s.substr(pos.first, pos.second - pos.first + 1) + close);
            last = pos.second + 1;
        }
        if(last < s.length()) result += s.substr(last);
        return result;
    }
    vector<pair<int, int>> find(string& s, unordered_map<int, unordered_set<string>> words){
        vector<pair<int, int>> res;
        for(int i = 0; i < s.size(); i++){
            for(auto it: words){
                if(it.second.find(s.substr(i, it.first)) != it.second.end())
                    res.push_back(make_pair(i, i + it.first - 1));
            }
        }
        return res;
    }
    vector<pair<int, int>> merge(vector<pair<int, int>> range){
        vector<pair<int, int>> result;
        if(range.empty()) return result;
        sort(range.begin(), range.end());
printVector(range);
        int begin = range[0].first, end = range[0].second;
        for(int i = 1; i < range.size(); i++){
            if(end < range[i].first - 1){
                result.push_back(make_pair(begin, end));
                begin = range[i].first;
                end = range[i].second;
            }
            else{
                end = max(end, range[i].second);
            }
        }
        result.push_back(make_pair(begin, end));
printVector(result);
        return result;
    }
};

int main(void){
    cout << "string s: ";
    string s = readString();
    cout << "dict:" << endl;
    vector<string> dict = readVector<string>();
    //vector<string> dict{"abc", "123"};//= readVector<string>();
    Solution sol;
    string res = sol.addBoldTag(s, dict);
    cout << "result = ";
    cout << res << endl;
    return 0;
}
