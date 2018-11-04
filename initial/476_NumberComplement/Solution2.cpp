#include "../IOLib.hpp"

class Solution {
public:
    int findComplement(int num) {
        int mask = (1 << int(log2(num))) - 1;
        return ~num & mask;
    }
};

int main(void){
    int num = readInt();
    Solution solution;
    int result = solution.findComplement(num);
    cout << "The complement number for " << num << " is " << result << endl;
    return 0;
}
