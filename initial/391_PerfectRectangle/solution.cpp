#include "../IOLib.hpp"

/***
Check if all the corner points except outer corners are occuring in pairs.
Check if the sub-rectangle areas sum up to the outer contour area.
Time: O(n)
Space: O(n)
***/

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if(rectangles.empty()) return false;
        int minx = rectangles[0][0], miny = rectangles[0][1], maxx = rectangles[0][2], maxy = rectangles[0][3];
        int totalarea = 0;
        unordered_set<string> points;
        for(auto vec: rectangles){
            minx = min(minx, vec[0]); miny = min(miny, vec[1]);
            maxx = max(maxx, vec[2]); maxy = max(maxy, vec[3]);
            totalarea += (vec[3] - vec[1]) * (vec[2] - vec[0]);
            vector<string> corners = {to_string(vec[0]) + "," + to_string(vec[1]), to_string(vec[0]) + "," + to_string(vec[3]), to_string(vec[2]) + "," + to_string(vec[1]), to_string(vec[2]) + "," + to_string(vec[3])};
            for(string c: corners){
                if(points.find(c) == points.end()) points.insert(c);
                else points.erase(c);
            }
        }
        if(totalarea != (maxy - miny) * (maxx - minx)) return false;
        vector<string> corners = {to_string(minx) + "," + to_string(miny), to_string(minx) + "," + to_string(maxy), to_string(maxx) + "," + to_string(miny), to_string(maxx) + "," + to_string(maxy)};
        for(string c: corners){
            if(points.find(c) == points.end()) return false;
            else points.erase(c);
        }
        if(!points.empty()) return false;
        return true;
    }
};
