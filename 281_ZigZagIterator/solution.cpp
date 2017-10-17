#include "../IOLib.hpp"

/**
All operations in O(1).
Space: O(1) if reference to v1 and v2. But actually O(n) (copied vectors)?

Better solution uses queue! Attached code on the bottom.
**/

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        vec1 = v1;
        vec2 = v2;
        pos = 0;
        circle = 1;
    }

    int next() {
        int res;
        if(circle == 1){
            if(pos < vec1.size()){
                res = vec1[pos];
                if(pos < vec2.size()) circle = 2;
                else pos++;
                return res;
            }
            else{
                circle = 2;
            }
        }
        if(circle == 2){
            if(pos < vec2.size()){
                res = vec2[pos];
                if(pos + 1 < vec1.size()) circle = 1;
                pos++;
                return res;
            }
            else circle = 1;
        }
        return res;
    }

    bool hasNext() {
        if(pos >= vec1.size() && pos >= vec2.size()) return false;
        return true;
    }
    vector<int> vec1;
    vector<int> vec2;
    int pos;
    int circle;
};

/** Uses queue **/
class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.size() != 0)
            Q.push(make_pair(v1.begin(), v1.end()));
        if (v2.size() != 0)
            Q.push(make_pair(v2.begin(), v2.end()));
    }

    int next() {
        auto it = Q.front().first;
        auto endIt = Q.front().second;
        Q.pop();
        if (it + 1 != endIt)
            Q.push(make_pair(it+1, endIt));
        return *it;
    }

    bool hasNext() {
        return !Q.empty();
    }
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> Q;
};
/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
