#include "../IOLib.hpp"

/**
This is my original solution using hashmap.
Could also use an array with size 300 to store times.
But difficulty remains scaling...
**/

class HitCounter {
    unordered_map<int, int> counter;
    int diff = 299;
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        counter[timestamp]++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int sum = 0;
        for(int i = timestamp - diff; i <= timestamp; i++){
            if(counter.find(i) != counter.end())
                sum += counter[i];
        }
        return sum;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
