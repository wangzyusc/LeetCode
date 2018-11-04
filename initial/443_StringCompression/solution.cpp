#include "../IOLib.hpp"

/* Read and write with two pointers.
 * Time: O(n), Space: O(1)
 */
class Solution {
public:
    int compress(vector<char>& chars) {
        //if(chars.size() < 2) return chars.size();
        int j = 0, count = 1;
        for(int i = 1; i <= chars.size(); i++){
            if(i < chars.size() && chars[i] == chars[i-1]){
                count++;
            }
            else if(count == 1) chars[j++] = chars[i-1];
            else{
                string temp = to_string(count);
                count = 1;
                //should copy char here
                chars[j++] = chars[i-1];
                for(auto& c: temp)
                    chars[j++] = c;
            }
        }
        return j;
    }
};
