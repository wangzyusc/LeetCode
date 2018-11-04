import java.util.Scanner;

class Tester{
    public static void main(String[] args){
	System.out.println("Input the array:");
	Scanner sc = new Scanner(System.in);
	String line = sc.nextLine();
	String[] segments = line.split(" ");
	int[] nums = new int[segments.length];
	for(int i = 0; i < segments.length; i++){
	    nums[i] = Integer.parseInt(segments[i]);
	}
	System.out.print("Input the position distance threshold: ");
	int k = sc.nextInt();
	System.out.print("Input the value distance threshold: ");
	int t = sc.nextInt();
	boolean result = Solution.containsNearbyAlmostDuplicate(nums, k, t);
	if(result) System.out.print("The input contains ");
	else System.out.print("The input doesn't contain ");
	System.out.println("duplicate that follow the condition.");
    }
}