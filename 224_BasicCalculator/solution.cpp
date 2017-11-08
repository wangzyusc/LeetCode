#include "../IOLib.hpp"

/***
Using stack.
Problem is have to use two more stacks when dealing ')'.
Could be solved by keeping track of sign.
Time: O(n)
Space: O(n)
***/
class Solution {
public:
    int calculate(string s) {
        stack<int> operands;
        stack<char> operators;
        s = '(' + s + ')';
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c == '(' || c == '+' || c == '-') operators.push(c);
            else if(c == ')'){
                stack<int> temp_num;
                stack<char> temp_ope;
                do{
                    temp_num.push(operands.top()); operands.pop();
                    temp_ope.push(operators.top()); operators.pop();
                }while(temp_ope.top() != '(');
                temp_ope.pop();
                while(!temp_ope.empty()){
                    int first = temp_num.top(); temp_num.pop();
                    int second = temp_num.top(); temp_num.pop();
                    char ope = temp_ope.top(); temp_ope.pop();
                    temp_num.push((ope=='+')?(first+second):(first-second));
                }
                operands.push(temp_num.top());
            }
            else if(isdigit(c)){
                int num = c - '0';
                while(isdigit(s[++i]))
                    num = 10 * num + (s[i] - '0');
                operands.push(num);
                i--;
            }
        }
        return operands.top();
    }
};
