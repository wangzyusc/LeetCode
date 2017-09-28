#include "../IOLib.hpp"

class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int size = str.size();
        if(size == 1) return num;
        for(int i = 0; i < str.size() - 1; i++){
            int pos = i;
            for(int j = i+1; j < str.size(); j++){
                if(str[j] >= str[pos]) pos = j;
            }
            if(str[pos] > str[i]){
                swap(str[i], str[pos]);
                break;
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
