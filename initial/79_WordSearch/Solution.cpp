#include "../IOLib.hpp"

class Solution {
private:
    int rows;
    int cols;
    char target;
    int bias[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<vector<bool> > visited;
public:
    bool exist(vector<vector<char> >& board, string word) {
        if(word.size() == 0) return true;
        initialize(board, word);
        for(int y = 0; y < rows; y++){
            for(int x = 0; x < cols; x++){
                if(search(board, word, y, x, 0))
                    return true;
            }
        }
        return false;
    }
    void initialize(vector<vector<char> >& board, string& word){
        rows = board.size();
        cols = board[0].size();
        target = word[0];
        for(int i = 0; i < rows; i++){
            vector<bool> row(cols, false);
            visited.push_back(row);
        }
    }
    bool search(vector<vector<char> >& board, string& word, int y, int x, int pos){
        if(board[y][x] != word[pos]) return false;
        if(pos == (word.size() - 1)) return true;
        visited[y][x] = true;
        for(int i = 0; i < 4; i++){
            int yy = y + bias[i][0], xx = x + bias[i][1];
            if(check_in_bound(yy, xx) && !visited[yy][xx]){
                if(search(board, word, yy, xx, pos + 1))
                    return true;
            }
        }
        visited[y][x] = false;
        return false;
    }
    bool check_in_bound(int y, int x){
        return (y >= 0) && (y < rows) && (x >= 0) && (x < cols);
    }
};

int main(void){
    cout << "Line number: ";
    int line_num = readInt();
    cout << "Target word: ";
    string word = readString();
    cout << "Board:" << endl;
    vector<string> board = readVectorOfStrings(line_num);
    vector<vector<char> > cvt_board;
    for(auto item: board){
        vector<char> vec(item.size());
        for(int i = 0; i < item.size(); i++){
            vec[i] = item[i];
        }
        cvt_board.push_back(vec);
    }
    Solution solution;
    string contains = (solution.exist(cvt_board, word)? "contains ":"doesn't contain ");
    cout << "The board " << contains << word << endl;
    return 0;
}
