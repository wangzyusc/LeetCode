#include "../IOLib.hpp"

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        for(auto str: dictionary){
            dict[getAbbr(str)].insert(str);
        }
    }
    
    bool isUnique(string word) {
        string key = getAbbr(word);
        if(dict.find(key) == dict.end()) return true;
        if(dict[key].size() > 1) return false;
        else{//dict[key].size() == 1
            return dict[key].find(word) != dict[key].end();
        }
    }
    
private:
    unordered_map<string, unordered_set<string>> dict;
    
    string getAbbr(string s){
        if(s.length() <= 2) return s;
        return s[0] + to_string(s.length() - 2) + s[s.length() - 1];
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
