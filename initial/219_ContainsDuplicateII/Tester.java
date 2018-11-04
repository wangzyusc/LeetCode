class Tester{
    public static void main(String[] args){
	int[] nums1 = {1,2,3,4,2};
	boolean res1 = Solution.containsNearbyDuplicate(nums1, 2);
	boolean res2 = Solution.containsNearbyDuplicate(nums1, 3);
	System.out.println(nums1 + " " + 2 + " -> " + res1);
	System.out.println(nums1 + " " + 3 + " -> " + res2);
    }
}