#include "../IOLib.hpp"

/***
Backtrack.
Time: O((n/2)!)
Space: O(n)
Could use a hashmap to store visited chessboard to reduce duplicates.
***/

class Solution {
public:
    bool canWin(string s) {
        if(s.length() < 2) return false;
        vector<bool> state(s.size(), false);
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '+') state[i] = true;
        }
        return p1round(state);
    }
    bool p1round(vector<bool>& state){
        bool nomove = true, canwin = false;
        for(int i = 0; i < state.size() - 1; i++){
            if(!state[i] || !state[i+1]) continue;
            nomove = false;
            state[i] = state[i+1] = false;
            bool status = p2round(state);
            state[i] = state[i+1] = true;
            if(status){
                canwin = true;
                break;
            }
        }
        return (!nomove) && canwin;
    }
    bool p2round(vector<bool>& state){
        bool nomove = true, canwin = true;
        for(int i = 0; i < state.size() - 1; i++){
            if(!state[i] || !state[i+1]) continue;
            nomove = false;
            state[i] = state[i+1] = false;
            bool status = p1round(state);
            state[i] = state[i+1] = true;
            if(!status){
                canwin = false;
                break;
            }
        }
        return nomove || canwin;
    }
};
