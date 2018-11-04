#include "../IOLib.hpp"

/*
 * This solution is O(n) per move(). Could be better.
 * Another solution is O(1) per move(). It uses two arrays to indicate
 * numbers of player1s over player2s. If anyone reaches n or -n, then
 * corresponding player wins. Also don't forget to include diagnal and
 * anti-diagnal.
 */
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        sz = n;
        board = vector<vector<int>>(n, vector<int>(n, 0));
        p = vector<vector<bool>>(2, vector<bool>(2 * n + 2, true));
        pcount[0] = pcount[1] = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        pcount[player - 1]++;
        board[row][col] = player;
        p[2 - player][row] = false;
        p[2 - player][sz + col] = false;
        if(col == row) p[2 - player][2 * sz] = false;
        if(col + row == sz - 1) p[2 - player][2 * sz + 1] = false;
        return ((pcount[player-1]>=sz) && checkWin(row, col, player)) ? player : 0;
    }
    bool checkWin(int row, int col, int player){
        int i;
        if(p[player - 1][row]){
            for(i = 0; i < sz; i++)
                if(board[row][i] != player)
                    break;
            if(i == sz)
                return true;
        }
        if(p[player - 1][sz + col]){
            for(i = 0; i < sz; i++)
                if(board[i][col] != player)
                    break;
            if(i == sz)
                return true;
        }
        if(row == col && p[player - 1][2 * sz]){
            for(i = 0; i < sz; i++)
                if(board[i][i] != player)
                    break;
            if(i == sz)
                return true;
        }
        if(row + col == sz - 1 && p[player - 1][2 * sz + 1]){
            for(i = 0; i < sz; i++)
                if(board[i][sz - i - 1] != player)
                    break;
            if(i == sz)
                return true;
        }
        return false;
    }
private:
    int sz;
    vector<vector<int>> board;
    vector<vector<bool>> p;
    int pcount[2];
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */

int main(void){
    TicTacToe t(3);
    t.move(0,0,1);
    t.move(0,2,2);
    t.move(2,2,1);
    t.move(1,1,2);
    t.move(2,0,1);
    t.move(1,0,2);
    t.move(2,1,1);
    return 0;
}
