#include "../IOLib.hpp"

/***
Original idea: generate a new string as the "feature" of each string.
Group strings with same feature into same result array.
Drawback: lots of string concatenation, slow.
***/
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> result;
        unordered_map<string, int> index;
        int count = 0;
        for(int i = 0; i < strings.size(); i++){
            string k = getKey(strings[i]);
            if(index.find(k) == index.end()){
                index[k] = count++;
                result.push_back(vector<string>(1, strings[i]));
            }
            else
                result[index[k]].push_back(strings[i]);
        }
        return result;
    }
    string getKey(string& src){
        string result = to_string((int)src.size());
        for(int i = 1; i < src.size(); i++){
            int num = src[i] - src[0];
            if(num < 0) num += 26;
            result += to_string(num);
        }
        return result;
    }
};

/***
Same idea with first solution, but avoided string concatenation.
Faster.
Time: O(n * avg_string_length)
Space: O(n * avg_string_length)
***/
class Solution2 {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> result;
        unordered_map<string, int> index;
        int count = 0;
        for(int i = 0; i < strings.size(); i++){
            string k = getKey(strings[i]);
            if(index.find(k) == index.end()){
                index[k] = count++;
                result.push_back(vector<string>(1, strings[i]));
            }
            else
                result[index[k]].push_back(strings[i]);
        }
        return result;
    }
    string getKey(string& src){
        string result = src;
        if(src.empty()) return result;
        result[0] = 'a';
        for(int i = 1; i < src.size(); i++){
            int num = src[i] - src[0];
            if(num < 0) num += 26;
            result[i] = 'a' + num;
        }
        return result;
    }
};

int main(void){
    vector<string> strings = readVector<string>();
    Solution sol;
    auto result = sol.groupStrings(strings);
    for(auto group: result){
        printVector(group);
    }
    return 0;
}
