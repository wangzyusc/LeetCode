#include "../IOLib.hpp"

class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0') return 0;
        if(s.size() == 1) return 1;
        //so now s.size() >= 2
        vector<int> nums(s.size(), 0);
        nums[0] = 1;
        nums[1] = (_valid(s[1]) ? 1 : 0) + (_valid(s[0], s[1]) ? 1 : 0);
        if(nums[1] == 0) return 0;
        for(int i = 2; i < s.size(); i++){
            if(_valid(s[i]))
                nums[i] += nums[i-1];
            if(_valid(s[i-1], s[i]))
                nums[i] += nums[i-2];
            if(nums[i] == 0) return 0;
        }
        return nums.back();
    }
    bool _valid(char c){
        return c != '0';
    }
    bool _valid(char c1, char c2){
        return (c1 == '1') || (c1 == '2' && c2 <= '6');
    }
};

int main(void){
    cout << "Input all digits: ";
    string input;
    cin >> input;
    Solution solution;
    cout << "There are " << solution.numDecodings(input)
         << " ways to decode " << input << endl;
    return 0;
}
