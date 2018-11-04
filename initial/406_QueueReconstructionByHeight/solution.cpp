#include "../IOLib.hpp"

/**
Sort: O(nlog(n))
Insert: O(n^2) (Could be improved?)
**/

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int,int>> result;
        /*sort(people.begin(), people.end(),
             [](pair<int, int>& a, pair<int, int>& b){
                 return (a.first == b.first) ? (a.second < b.second) : (a.first > b.first);
             });*/
        //both sort method works!
        sort(people.begin(), people.end());
        reverse(people.begin(), people.end());
        /*debug code*/cout << "After sort: " << endl;
        /*debug code*/printVector(people);
        for(auto p: people){
            int count = 0, pos = 0;
            while(pos < result.size() &&
                  count < p.second){
                if(result[pos].first >= p.first) count++;
                pos++;
            }
            result.insert(result.begin()+pos, p);
            /*debug code*/printVector(result);
        }
        return result;
    }
};

/**
More concise version. Since for each pair, all the pairs already in queue has bigger height than it.
We can just insert it to the position of its second value.
**/

vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2)
                    { return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second); };
    sort(people.begin(), people.end(), comp);
    vector<pair<int, int>> res;
    for (auto& p : people) 
        res.insert(res.begin() + p.second, p);
    return res;
}

int main(void){
    vector<pair<int, int>> people = readVector<pair<int,int>>();
    Solution sol;
    vector<pair<int, int>> res = sol.reconstructQueue(people);
    printVector(res);
    return 0;
}
