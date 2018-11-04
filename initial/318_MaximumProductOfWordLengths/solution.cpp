#include "../IOLib.hpp"

/***
Brute-force.
Use a vector with 26 entries to represent letter existance.
Time: O(n^2 * (26^2))
Space: O(n * 26) (O(n) but comparatively slower)
***/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int result = 0;
        vector<vector<int>> letters;
        for(int i = 0; i < words.size(); i++){
            vector<int> dict(26, 0);
            for(auto c: words[i])
                dict[c-'a']++;
            for(int j = 0; j < i; j++){
                bool overlap = false;
                for(auto c: words[i]){
                    if(letters[j][c-'a']){
                        overlap = true;
                        break;
                    }
                }
                if(!overlap) result = max(result, (int)words[i].size() * (int)words[j].size());
            }
            letters.push_back(dict);
        }
        return result;
    }
};

/***
Use bit-mask!
Use an integer to replace the vector in above version.
Time: O(n^2)
Space: O(n)
Still O(n^2) but faster.
***/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int result = 0;
        vector<int> letters;
        for(int i = 0; i < words.size(); i++){
            int dict = 0;
            for(auto c: words[i])
                dict |= (1 << (c-'a'));
            for(int j = 0; j < i; j++){
                if(!(dict & letters[j]))
                    result = max(result, (int)words[i].size() * (int)words[j].size());
            }
            letters.push_back(dict);
        }
        return result;
    }
};
