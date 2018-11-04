#include "../IOLib.hpp"

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int ssz = s.size(), tsz = t.size();
        if(abs(ssz - tsz) > 1) return false;
        if(ssz == tsz){
            bool diff = false;
            for(int i = 0; i < ssz; i++)
                if(s[i] != t[i]){
                    if(diff) return false;
                    else diff = true;
                }
            return diff;
        }
        else{//size diff is 1
            if(ssz == tsz + 1) swap(s, t);
            //t is larger than s by 1
            bool diff = false;
            for(int i = 0, j = 0; i < ssz; i++, j++){
                if(s[i] != t[j]){
                    if(diff) return false;
                    else{
                        diff = true;
                        i--;
                    }
                }
            }
            return true;
        }
    }
};

int main(void){
    string s = readString();
    string t = readString();
    Solution solution;
    bool is = solution.isOneEditDistance(s, t);
    cout << "\"" << s << "\" and \"" << t
         << "\" is " << (is?"":"not ")
         << "one edit distance."<< endl;
    return 0;
}
