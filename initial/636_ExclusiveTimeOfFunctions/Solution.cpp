#include "../IOLib.hpp"

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);
        stack<pair<int, int> > stk;
        for(auto log: logs){
            stringstream ss(log);
            string temp, status;
            getline(ss, temp, ':');
            int id = stoi(temp);
            getline(ss, status, ':');
            getline(ss, temp);
            int time = stoi(temp);
            if(status == "start"){
                if(!stk.empty()){
                    auto top = stk.top();
                    result[top.first] += (time - top.second);
                }
                stk.push(make_pair(id, time));
            }
            else{//status == "end"
                auto top = stk.top();
                result[id] += (time - top.second + 1);
                stk.pop();
                if(!stk.empty()){
                    top = stk.top();
                    stk.pop();
                    stk.push(make_pair(top.first, time + 1));
                }
            }
        }
        return result;
    }
};

int main(void){
    int num = readInt();
    vector<string> input = readVectorOfStrings(2 * num);
    Solution solution;
    vector<int> result = solution.exclusiveTime(num, input);
    printVector(result);
    return 0;
}
