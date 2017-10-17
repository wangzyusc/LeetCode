#include "../IOLib.hpp"

/**
This idea is OK, but could also use queue!
Time: next: O(1)
Space: O(n)
**/

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->nums = vector<int>(size);
        this->pos = 0;
        this->capacity = size;
        this->used = 0;
        this->sum = 0;
    }
    
    double next(int val) {
        int temp = nums[pos];
        nums[pos++] = val;
        if(++used > capacity) used = capacity;
        if(pos == capacity) pos = 0;
        sum += val; sum -= temp;
        return sum / used;
    }
private:
    vector<int> nums;
    int pos;
    int capacity;
    int used;
    double sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
