#include "../IOLib.hpp"

/***
This my original solution. But it's really troublesome to handle each cases.
First use a binary search to find the axis of the quadratic function, but it's unnecessary if we start from edges toward axis center instead of from axis to edges.
If use that solution, only need to determine a >= 0 or a < 0.
***/
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> result;
        if(nums.empty()) return result;
        if(a != 0){
            double axis = -b/(2.0*a);
            int l = 0, r = nums.size() - 1;
            while(l < r){
                int mid = l + (r - l) / 2;
                if(nums[mid] >= axis) r = mid;
                else l = mid + 1;
            }
            //now l = r = index of first element >= axis
            l--;
            vector<int> sorted;
            while(l >= 0 && r < nums.size()){
                double lval = axis - nums[l];
                double rval = nums[r] - axis;
                if(lval < rval)
                    sorted.push_back(nums[l--]);
                else
                    sorted.push_back(nums[r++]);
            }
            while(l >= 0)
                sorted.push_back(nums[l--]);
            while(r < nums.size())
                sorted.push_back(nums[r++]);
            if(a > 0){
                for(auto n: sorted){
                    result.push_back(a * pow(n, 2) + b * n + c);
                }
            }
            else{
                for(auto it = sorted.rbegin(); it != sorted.rend(); it++){
                    result.push_back(a * pow(*it, 2) + b * (*it) + c);
                }
            }
        }
        else if(b >= 0){
            for(auto n: nums)
                result.push_back(b * n + c);
        }
        else{
            for(auto it = nums.rbegin(); it != nums.rend(); it++){
                result.push_back(b * (*it) + c);
            }
        }
        return result;
    }
};
