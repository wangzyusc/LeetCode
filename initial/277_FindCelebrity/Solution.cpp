#include "../IOLib.hpp"

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        if(n == 0) return -1;
        if(n == 1) return 0;
        set<int> known;
        for(int i = 0; i < n; i++) known.insert(i);
        for(int i = 0; known.size() > 1 && i < n; i++){
            if(known.find(i) == known.end()) continue;
            set<int> unknown;
            for(set<int>::iterator it = known.begin(); it != known.end(); it++){
                if(*it != i){
                    if(!knows(i, *it)) unknown.insert(*it);
                    else if(knows(*it, i)) unknown.insert(*it);
                }
            }
            for(set<int>::iterator it = unknown.begin(); it != unknown.end(); it++)
                known.erase(*it);
        }
        if(known.size() != 1) return -1;
        int res = *(known.begin());
        for(int i = 0; i < n; i++){
            if(res == i) continue;
            if(knows(res, i)) return -1;
            if(!knows(i, res)) return -1;
        }
        return res;
    }
};

int main(void){
    return 0;
}
