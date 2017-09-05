#include "../IOLib.hpp"

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        initialize();
        vector<string> res;
        for(string word: words){
            if(is_one_row(word)){
                res.push_back(word);
            }
        }
        return res;
    }
    void initialize(){
        for(char c: first_row){
            rows[c] = 1;
            rows[c-'a'+'A'] = 1;
        }
        for(char c: second_row){
            rows[c] = 2;
            rows[c-'a'+'A'] = 2;
        }
        for(char c: third_row){
            rows[c] = 3;
            rows[c-'a'+'A'] = 3;
        }
    }
    bool is_one_row(string& word){
        int row = rows[word[0]];
        for(int i = 1; i < word.size(); i++){
            if(rows[word[i]] != row) return false;
        }
        return true;
    }
private:
    const vector<char> first_row = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    const vector<char> second_row = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    const vector<char> third_row = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
    unordered_map<char, int> rows;
};

int main(void){
    cout << "Number of words: ";
    int num = readInt();
    cout << "Input words line by line:" << endl;
    vector<string> words = readVectorOfStrings(num);
    Solution solution;
    vector<string> result = solution.findWords(words);
    cout << "The result is:" << endl;
    printVectorOfStrings(result);
    return 0;
}
