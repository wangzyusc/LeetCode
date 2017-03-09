import java.util.HashSet;

public class Solution {
    public static boolean containsDuplicate(int[] nums) {
        if(nums.length <= 1) return false;
        HashSet<Integer> set = new HashSet<Integer>();
        for(int num : nums){
            if(!set.add(num)) return true;
        }
        return false;
    }
}