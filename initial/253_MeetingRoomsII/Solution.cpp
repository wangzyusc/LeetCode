#include "../IOLib.hpp"

/**
 * Definition for an interval.
 */
struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
private:
    static bool compare(const Interval& a, const Interval& b){
        return a.start < b.start;
    }
    class mycomparison {
        public:
            bool operator() (Interval*& a, Interval*& b) const {
                return a->end > b->end;
            }
    };
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() < 2) return intervals.size();
        sort(intervals.begin(), intervals.end(), compare);
        priority_queue<Interval*, vector<Interval*>, mycomparison> q;
        int rooms = 1;
        for(int i = 0; i < intervals.size(); i++){
            int start = intervals[i].start;
            while(!q.empty() && q.top()->end <= start) q.pop();
            q.push(&intervals[i]);
            rooms = max(rooms, (int)q.size());
        }
        return rooms;
    }
};
