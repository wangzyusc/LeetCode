#include "../IOLib.hpp"

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> unvisited(wordList.begin(), wordList.end());
        if(unvisited.find(endWord) == unvisited.end()) return 0;
        unordered_map<string, int> visited;
        visited[beginWord] = 1;
        queue<string> line;
        line.push(beginWord);
        while(!line.empty()){
            string cur = line.front();
            line.pop();
            if(cur == endWord) return visited[cur];
            unvisited.erase(cur);
            int count = visited[cur] + 1;
            for(int i = 0; i < cur.size(); i++){
                char c = cur[i];
                for(int j = 0; j < 26; j++){
                    cur[i] = 'a' + j;
                    if(visited.find(cur) != visited.end()) continue;
                    if(unvisited.find(cur) == unvisited.end()) continue;
                    if(endWord == cur) return count;
                    line.push(cur);
                    visited[cur] = count;
                }
                cur[i] = c;
            }
        }
        return 0;
    }
};

int main(void){
    cout << "Start word: ";
    string start = readString();
    cout << "End word: ";
    string end = readString();
    cout << "Word dict: " << endl;
    cout << "Length: ";
    int len = readInt();
    vector<string> dict = readVectorOfStrings(len);
    Solution solution;
    int num = solution.ladderLength(start, end, dict);
    cout << "The length is " << num << "." << endl;
    return 0;
}
