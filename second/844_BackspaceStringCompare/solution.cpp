#include "../../IOLib.hpp"

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s, t;
	for(auto& c: S){
            if(c == '#'){
                if(!s.empty())
                    s.pop();
	    }
            else s.push(c);
        }
        for(auto& c: T){
            if(c == '#'){
                if(!t.empty())
                    t.pop();
	    }
            else t.push(c);
        }
        if(s.size() != t.size()) return false;
        while(s.size()){
            if(s.top() != t.top()) return false;
            s.pop();
            t.pop();
        }
        return true;
    }
};

int main(void){
	string s = readString();
	string t = readString();
	Solution sol;
	auto res = sol.backspaceCompare(s, t);
	cout << "res = " << res << endl;
	return 0;
}
