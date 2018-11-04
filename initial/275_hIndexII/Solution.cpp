#include "../IOLib.hpp"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0) return 0;
        int h = 0;
        int left = 0, count = citations.size();
        int step = 0;
        while(count > 0){
            step = count / 2;
            int mid = left + step;
            h = citations.size() - mid;
            if(citations[mid] < h){
                left = mid + 1;
                count -= (step + 1);
            }
            else{
                count = step;
            }
        }
        return citations.size() - left;
    }
};

int main(void){
    vector<int> citations;
    readVector(citations);
    Solution sol;
    cout << "hIndex = " << sol.hIndex(citations) << endl;
    return 0;
}
