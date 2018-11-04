#include "../IOLib.hpp"

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int length = nums.size();
        if(length == 3) return nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        int bestSum = nums[0]+nums[1]+nums[2];
        if(bestSum >= target) return bestSum;
        //now: bestSum < target
        if(nums[length-3]+nums[length-2]+nums[length-1] <= target)
            return nums[length-3]+nums[length-2]+nums[length-1];
        int bestDist = abs(bestSum - target);
        for(int i = 0; i < length - 2; i++){
        	if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < length - 1; j++){
                int left = j + 1, right = length - 1;
                int localTarget = target - nums[i] - nums[j];
                while(left < right){
                    int mid = (left + right) / 2;
                    if(nums[mid] == localTarget) return target;
                    if(nums[mid] > localTarget){
                        right = mid;
                    }
                    else{//nums[mid] < localTarget
                        left = mid + 1;
                    }
                    int dist = abs(nums[mid] - localTarget);
	                if(dist == 0) return target;
	                if(dist < bestDist){
	                    bestDist = dist;
	                    bestSum = nums[i] + nums[j] + nums[mid];
	                }
                }
                //left == right
                int dist = abs(nums[left] - localTarget);
                if(dist == 0) return target;
                if(dist < bestDist){
                    bestDist = dist;
                    bestSum = nums[i] + nums[j] + nums[left];
                }
            }
        }
        return bestSum;
    }
};

int main(){
	vector<int> nums;
	readVector(nums);
	int target = readInt();
	Solution solution;
	int result = solution.threeSumClosest(nums, target);
	cout << "The result is " << result << endl;
	return 0;
}