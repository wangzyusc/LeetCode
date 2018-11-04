#include "../IOLib.hpp"

class Solution {
public:
    string addBinary(string a, string b) {
        string res(max(a.size(), b.size()) + 1, '0');
        string::reverse_iterator ita = a.rbegin(), 
                         itb = b.rbegin(),
                         itr = res.rbegin();
        int forward = 0;
        while(ita != a.rend() && itb != b.rend()){
            char x = *ita, y = *itb;
            *itr = '0' + (x - '0' + y - '0' + forward) % 2;
            forward = (x - '0' + y - '0' + forward) / 2;
            ita++; itb++; itr++;
        }
        while(ita != a.rend()){
            *itr = '0' + (*ita - '0' + forward) % 2;
            forward = (*ita - '0' + forward) / 2;
            ita++; itr++;
        }
        while(itb != b.rend()){
            *itr = '0' + (*itb - '0' + forward) % 2;
            forward = (*itb - '0' + forward) / 2;
            itb++; itr++;
        }
        if(forward) *itr = '1';
        else res = res.substr(1);
        return res;
    }
};

int main(void){
    cout << "Please input 2 binary numbers:" << endl;
    string num1, num2;
    cin >> num1;
    cin >> num2;
    Solution solution;
    cout << "The sum of these 2 number is " << solution.addBinary(num1, num2) << endl;
    return 0;
}
