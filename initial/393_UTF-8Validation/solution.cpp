#include "../IOLib.hpp"

/**
For each element in array, at most 4 iterations if it's head of a character,
or only 1 time of access if it's single letter or following data.
Time: O(n)
Space: O(1)
**/

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        if(n == 1){
            return ((data[0] & 128) == 0);
        }
        int next = 0;
        while(next < n){
            if((data[next] & 128) == 0){
                next++;
            }
            else{//multiple-bytes
                int len = 2;
                while(len <= 4 && ((data[next] & head_mask[len+1]) != head_mask[len])){
                    len++;
                }
                if(len > 4) return false;
                //so data[next] & head_mask[len+1] == head_mask[len]
                if(next + len > n) return false;
                for(int i = 1; i < len; i++){
                    if((data[next+i] & data_mask) != data_res) return false;
                }
                next = next + len;
            }
        }
        return true;
    }
private:
    vector<int> head_mask{0,128,192,224,240,248,252,254,255,255};
    int data_mask = 192;
    int data_res = 128;
};
