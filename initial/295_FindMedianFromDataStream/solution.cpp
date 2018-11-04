#include "../IOLib.hpp"

/***
Use two priority queues to store top and bottom halves of data.
Time: O(log(n))
Space: O(n)
***/

class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> large;
    priority_queue<int, vector<int>> small;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if((large.size() == small.size()) && ((small.size() == 0) || (small.top() <= num))){
            large.push(num);
        }
        else if(large.size() == small.size()){
            int tmp = small.top();
            small.pop();
            small.push(num);
            large.push(tmp);
        }
        else if(num <= large.top()){
            small.push(num);
        }
        else{
            int tmp = large.top();
            large.pop();
            large.push(num);
            small.push(tmp);
        }
    }
    
    double findMedian() {
        if(large.size() == small.size()){
            return (large.top() + small.top()) / 2.0;
        }
        else return large.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
