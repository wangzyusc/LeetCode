import java.util.Map;
import java.util.HashMap;

public class Solution {
    public static int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];
        int length = nums.length;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i = 0; i < length; i++){
            if(map.containsKey(target - nums[i]) == true){
                result[0] = map.get(target - nums[i]);
                result[1] = i;
                return result;
            }
            else{
                map.put(nums[i], i);
            }
        }
        result[0] = 0;
        result[1] = 1;
        return result;
    }
}
