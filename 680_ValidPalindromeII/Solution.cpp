#include "../IOLib.hpp"

class Solution {
public:
    bool validPalindrome(string s) {
        int size = s.size(), i = 0, j = s.size() - 1;
        while(i <= j && s[i] == s[j]){
            i++; j--;
        }
        if(i > j) return true;
        int curi = i, curj = j;
        i++;
        while(i <= j && s[i] == s[j]){
            i++; j--;
        }
        if(i > j) return true;
        i = curi;
        j = curj - 1;
        while(i <= j && s[i] == s[j]){
            i++; j--;
        }
        if(i > j) return true;
        return false;
    }
};

int main(void){
    string s = readString();
    Solution sol;
    bool res = sol.validPalindrome(s);
    cout << (res?"true":"false") << endl;
    return 0;
}
