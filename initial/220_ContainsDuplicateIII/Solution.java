import java.util.HashMap;

public class Solution {
    public static boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        if(nums.length <= 1 || t < 0) return false;
        HashMap<Long, Integer> map = new HashMap<Long, Integer>();
        long denominator = ((long)t) + 1;
        for(int i = 0; i < nums.length; i++){
            if(i > k){
                map.remove((long)nums[i-k-1] / denominator);
            }
            long product = ((long)nums[i]) / denominator;
            if((map.containsKey(product) && (Math.abs(((long)nums[i]) - ((long)map.get(product))) <= t))
               || (map.containsKey(product - 1) && (nums[i] - map.get(product-1) <= t))
               || (map.containsKey(product + 1) && (map.get(product+1) - nums[i] <= t)))
		return true;
            map.put(product, nums[i]);
        }
        return false;
    }
}