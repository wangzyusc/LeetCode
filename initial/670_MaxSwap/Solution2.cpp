#include "../IOLib.hpp"

class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int size = str.size();
        if(size == 1) return num;
        vector<int> cand(size, 0);
        int tmp = size - 1;
        for(int i = size - 1; i >= 0; i--){
            if(str[i] > str[tmp]){
                tmp = i;
                cand[i] = tmp;
            }
            else{
                cand[i] = tmp;
            }
        }
        for(int i = 0; i < size; i++){
            if(str[i] != str[cand[i]]){
                swap(str[i], str[cand[i]]);
                return stoi(str);
            }
        }
        return stoi(str);
    }
};

int main(void){
    int num = readInt();
    Solution solution;
    int res = solution.maximumSwap(num);
    cout << "res = " << res << endl;
    return 0;
}
