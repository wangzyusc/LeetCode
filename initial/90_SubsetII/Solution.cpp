#include "../IOLib.hpp"

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        map<int, int> counts;
        for(auto num: nums) counts[num]++;
        vector<vector<int> > result;
        result.push_back(vector<int>(0));
        for(auto it = counts.begin(); it != counts.end(); it++){
            vector<vector<int> > stk(it->second);
            for(int i = 1; i <= it->second; i++){
                vector<int> temp(i, it->first);
                stk[i-1] = temp;
            }
            setmultiply(result, stk);
        }
        return result;
    }
    void setmultiply(vector<vector<int> >& set1,
                     vector<vector<int> >& set2){
        int size = set1.size();
        for(auto vec: set2){
            for(int i = 0; i < size; i++){
                vector<int> new_vec;
                new_vec.reserve(vec.size() + set1[i].size());
                new_vec.insert(new_vec.end(), set1[i].begin(), set1[i].end());
                new_vec.insert(new_vec.end(), vec.begin(), vec.end());
                set1.push_back(new_vec);
            }
        }
    }
};

int main(void){
    vector<int> nums;
    readVector(nums);
    Solution sol;
    vector<vector<int> > res = sol.subsetsWithDup(nums);
    printMatrix(res);
    return 0;
}
