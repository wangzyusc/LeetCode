#include "../IOLib.hpp"

/**
Two-pointers. Two iterations: front->end and end->front.
Time: O(n)
Space: O(1)
**/

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = 0, i = 0, j = 0;
        int count = 0;
        while(i < s.length()){
            if(s[i] == '(') count++;
            if(s[i] == ')') count--;
            //cout << "i = " << i << ", count = " << count << endl;
            while(count < 0 && j < i){
                if(s[j] == '(') count--;
                if(s[j] == ')') count++;
                //cout << " j = " << j << ", count = " << count << endl;
                j++;
            }
            if(count == 0){
                len = max(len, i - j + 1);
            }
            else if(count < 0){
                count = 0;
                j = i + 1;
            }
            i++;
        }
        count = 0;
        i = j = s.length() - 1;
        while(i >= 0){
            if(s[i] == '(') count--;
            if(s[i] == ')') count++;
            //cout << "i = " << i << ", count = " << count << endl;
            while(count < 0 && j > i){
                if(s[j] == '(') count++;
                if(s[j] == ')') count--;
                //cout << " j = " << j << ", count = " << count << endl;
                j--;
            }
            if(count == 0){
                len = max(len, j - i + 1);
            }
            else if(count < 0){
                count = 0;
                j = i - 1;
            }
            i--;
        }
        return len;
    }
};

/**
Using a stack to store indecies of '('.
Time: O(n)
Space: O(n)
**/
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() == 0) {
            return 0;
        }
        stack<int> stk;
        stk.push(-1);
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    res = max(res, i - stk.top());
                }
            }
        }
        return res;
    }
};
