#include "../IOLib.hpp"

/**
Use recursion as stack. Or use stack manually.
Time: O(n)
Space: O(# hierachy)
**/

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
    string decode(string s, int& i){
        string result;
        while(i < s.size() && s[i] != ']'){
            if(!isdigit(s[i])){
                result += s[i++];
            }
            else{
                int num = 0;
                while(isdigit(s[i]))
                    num = 10 * num + (s[i++] - '0');
                i++;
                string sub = decode(s, i);
                i++;
                while(num-- > 0)
                    result += sub;
            }
        }
        return result;
    }
};

int main(void){
    Solution sol;
    string s = readString();
    string res = sol.decodeString(s);
    cout << res << endl;
    return 0;
}
