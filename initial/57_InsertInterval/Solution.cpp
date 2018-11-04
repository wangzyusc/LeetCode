#include "../IOLib.hpp"

/**
 * Definition for an interval.
 **/
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if(intervals.size() == 0){
            intervals.push_back(newInterval);
            return intervals;
        }
        int i = 0;
        while(i < intervals.size() &&
              intervals[i].end < newInterval.start)
            i++;
        if(i == intervals.size()){
            intervals.push_back(newInterval);
            return intervals;
        }
        int start_idx = i, start = min(newInterval.start, intervals[start_idx].start);
        while(i < intervals.size() &&
              intervals[i].start <= newInterval.end)
            i++;
        //if(i == intervals.size()) i--;
        int end_idx = i - 1, end = max(newInterval.end, intervals[end_idx].end);
        intervals.erase(intervals.begin() + start_idx, intervals.begin() + end_idx + 1);
        Interval element(start, end);
        intervals.insert(intervals.begin() + start_idx, element);
        return intervals;
    }
};

int main(void){
    return 0;
}
