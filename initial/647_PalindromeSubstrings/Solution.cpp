#include "../IOLib.hpp"

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            countFromCenter(s, i, i, res);
            countFromCenter(s, i, i+1, res);
        }
        return res;
    }
    void countFromCenter(const string& s, int left, int right, int& sum){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            sum++;
            left--;
            right++;
        }
    }
};

int main(void){
    string s = readString();
    Solution sol;
    cout << "res = " << sol.countSubstrings(s) << endl;
    return 0;
}
