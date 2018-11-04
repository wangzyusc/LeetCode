#include "../IOLib.hpp"

class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        int weight = 1;
        while(num){//num != 0
            if(num % 2 == 0) res += weight;
            weight *= 2;
            num = num >> 1;
        }
        return res;
    }
};

int main(void){
    int num = readInt();
    Solution solution;
    int result = solution.findComplement(num);
    cout << "The complement number for " << num << " is " << result << endl;
    return 0;
}
