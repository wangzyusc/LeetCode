#include "../IOLib.hpp"

class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        int index = 0;
        while(index < s.size() && s[index] == ' ')
            index++;
        bool pre_valid = index < s.size();
        while(++index < s.size()){
            if(pre_valid && s[index] == ' '){
                count++;
                pre_valid = false;
            }
            else if(!pre_valid && s[index] != ' '){
                pre_valid = true;
            }
        }
        if(pre_valid) count++;
        return count;
    }
};

int main(void){
    string s = readString();
    Solution solution;
    cout << "Number of segments is " << solution.countSegments(s) << endl;
    return 0;
}
