#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};

int main(void){
	int num = readInt();
	Solution solution;
	cout << "You will " << (solution.canWinNim(num)?"win":"lose") << "." << endl;
	return 0;
}