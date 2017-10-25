#include "../IOLib.hpp"

/***
Notice the way of determining what is the subsequence.
Time: O(n*length(string))
Space: O(1)
***/
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res;
        for(string item: d){
            if(subsequence(s, item)){
                if(res.empty() || item.length() > res.length() || (item.length() == res.length() && item < res))
                    res = item;
            }
        }
        return res;
    }
    bool subsequence(string parent, string child){
        if(parent.length() < child.length()) return false;
        int i = 0, j = 0, plen = parent.length(), clen = child.length();
        while(i < plen && j < clen){
            if(parent[i] == child[j]){
                i++; j++;
            }
            else i++;
        }
        if(j == clen) return true;
        return false;
    }
};

/**
BFS. Time Limit Exceeded.
Time: O(n!)
Space: O(n!)
**/
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        vector<string> candidates;
        unordered_set<string> dict(d.begin(), d.end());
        queue<string> q;
        unordered_set<string> history;
        q.push(s);
        history.insert(s);
        bool found = false;
        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i < len; i++){
                string cur = q.front();
                q.pop();
                if(dict.find(cur) != dict.end()){
                    candidates.push_back(cur);
                    found = true;
                }
                else{
                    for(int i = 0; i < cur.size(); i++){
                        string next = cur.substr(0, i) + cur.substr(i + 1);
                        if(history.find(next) == history.end()){
                            q.push(next);
                            history.insert(next);
                        }
                    }
                }
            }
            if(found) break;
        }
        sort(candidates.begin(), candidates.end());
        return candidates.front();
    }
};
