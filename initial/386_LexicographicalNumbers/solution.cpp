#include "../IOLib.hpp"

/* Using a stack (as DFS), each number * 10 or + 1.
 * Time: O(n), Space: O(n)
 */
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result(n);
        stack<int> stack;
        stack.push(1);
        int index = 0;
        while(index < n){
            int temp = stack.top();
            stack.pop();
            result[index++] = temp;
            if((temp % 10 != 9) && (temp + 1 <= n)) stack.push(temp + 1);
            if(temp * 10 <= n) stack.push(temp * 10);
        }
        return result;
    }
};
