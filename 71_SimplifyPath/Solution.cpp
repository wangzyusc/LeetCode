#include "../IOLib.hpp"

class Solution {
public:
    string simplifyPath(string path) {
        if(path == "/") return path;
        stringstream ss(path);
        string temp;
        stack<string> strs;
        while(getline(ss, temp, '/')){
            if(temp == ".") continue;
            else if(temp == ".."){
                if(!strs.empty()) strs.pop();
            }
            else if(temp != "") strs.push(temp);
        }
        string result = "";
        while(strs.size() > 0){
            result = "/" + strs.top() + result;
            strs.pop();
        }
        if(result == "") result = "/";
        return result;
    }
};

int main(void){
    Solution solution;
    string input = readString();
    string result = solution.simplifyPath(input);
    cout << "Result is:" << endl;
    cout << result << endl;
    return 0;
}
