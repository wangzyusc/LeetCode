public class NumArray {
    private int[] sums;
    public NumArray(int[] nums) {
        if(nums != null){
            sums = new int[nums.length + 1];
            for(int j = 0; j < nums.length; j++)
                sums[j+1] = sums[j] + nums[j];
        }
    }
    
    public int sumRange(int i, int j) {
        return sums[j+1] - sums[i];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */