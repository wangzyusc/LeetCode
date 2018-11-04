#include "../IOLib.hpp"

/* This one is like find the next permutation problem.
 * Could be improved by replace sort() by reverse().
 * Time: O(log(n)) (linear with the length of string).
 * Space: O(log(n)) (string space)
 */
class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int i = str.size() - 2;
        while(i >= 0 && str[i] >= str[i + 1])
            i--;
        if(i < 0) return -1;
        int j = str.size() - 1;
        while(j > i && str[j] <= str[i])
            j--;
        swap(str[i], str[j]);
        //Could replace the sort below by reverse
        sort(str.begin() + i + 1, str.end());
        int result;
        try{
            result = stoi(str);
        }
        catch(out_of_range){
            return -1;
        }
        return result;
    }
};
