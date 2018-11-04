#include "../IOLib.hpp"

/**
Brute-force. Time Limit Exceeded.
**/

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int result = 0;
        int row = 1;
        int i = 0;
        while(row <= rows){
            int cap = cols;
            while((int)sentence[i].size() <= cap){
                cap -= (sentence[i].size() + 1);
                i++;
                if(i == sentence.size()){
                    i = 0;
                    result++;
                }
            }
            row++;
        }
        return result;
    }
};

/**
Store status transforming array.
Time: O(n * (cols / avg word length) + n)
Space: O(n)
**/

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        vector<int> times(sentence.size(), 0);
        vector<int> nextIndex(sentence.size(), -1);
        for(int i = 0; i < sentence.size(); i++){
            int cap = cols;
            int cur = i;
            while((int)sentence[cur].size() <= cap){
                cap -= (sentence[cur].size() + 1);
                cur++;
                if(cur == sentence.size()){
                    cur = 0;
                    times[i]++;
                }
            }
            nextIndex[i] = cur;
        }
        int result = 0;
        int cur = 0;
        for(int i = 1; i <= rows; i++){
            result += times[cur];
            cur = nextIndex[cur];
        }
        return result;
    }
};

int main(void){
    int len = readInt();
    vector<string> sentence = readVectorOfStrings(len);
    int rows = readInt();
    int cols = readInt();
    Solution sol;
    int res = sol.wordsTyping(sentence, rows, cols);
    cout << res << endl;
    return 0;
}
