#include "../IOLib.hpp"

/* Use STL list api to simplify code */
/* Time: put: O(1), get: O(1)
 * Space: O(n)
 */
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(hash.find(key) == hash.end()) return -1;
        sequence.erase(hash[key].second);
        sequence.push_front(key);
        hash[key].second = sequence.begin();
        return hash[key].first;
    }
    
    void put(int key, int value) {
        if(hash.find(key) != hash.end()){
            sequence.erase(hash[key].second);
        }
        else if(hash.size() == cap){
            int last = sequence.back();
            sequence.pop_back();
            hash.erase(last);
        }
        sequence.push_front(key);
        hash[key] = make_pair(value, sequence.begin());
    }
    int cap;
    unordered_map<int, pair<int, list<int>::iterator>> hash;
    list<int> sequence;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
