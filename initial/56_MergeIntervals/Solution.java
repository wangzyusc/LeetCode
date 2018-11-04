import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public List<Interval> merge(List<Interval> intervals) {
        if(intervals.size() <= 1) return intervals;
        List<Interval> result = new ArrayList<>();
        int len = intervals.size();
        int[] starts = new int[len];
        int[] ends = new int[len];
        int i = 0;
        for(Interval item : intervals){
            starts[i] = item.start;
            ends[i++] = item.end;
        }
        Arrays.sort(starts);
        Arrays.sort(ends);
        int j = 0;
        for(i = 0; i < len; i++){
            if(i == len-1 || starts[i+1] > ends[i]){
                result.add(new Interval(starts[j], ends[i]));
                j = i+1;
            }
        }
        return result;
    }
}