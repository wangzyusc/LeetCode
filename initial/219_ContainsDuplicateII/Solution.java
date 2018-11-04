import java.util.HashSet;
//import java.util.Math;

public class Solution {
    public static boolean containsNearbyDuplicate(int[] nums, int k) {
        int len = nums.length;
        k = Math.min(len, k + 1);
        HashSet<Integer> set = new HashSet<Integer>();
        for(int i = 0; i < k; i++){
            if(!set.add(nums[i])) return true;
        }
        for(int i = k; i < len; i++){
            set.remove(nums[i-k]);
            if(!set.add(nums[i])) return true;
        }
        return false;
    }
}