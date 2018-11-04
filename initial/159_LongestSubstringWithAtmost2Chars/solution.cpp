#include "../IOLib.hpp"

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> counts;
        int i = 0, j = 0, len = 0;
        while(i < s.length()){
            counts[s[i]]++;
            while(j < i - 1 && counts.size() > 2){
                counts[s[j]]--;
                if(counts[s[j]] == 0) counts.erase(s[j]);
                j++;
            }
            len = max(len, i - j + 1);
            i++;
        }
        return len;
    }
};

int main(void){
    string s = readString();
    Solution sol;
    int res = sol.lengthOfLongestSubstringTwoDistinct(s);
    cout << "res = " << res << endl;
    return 0;
}
