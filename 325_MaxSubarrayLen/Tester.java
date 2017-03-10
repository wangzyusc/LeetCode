import java.util.Scanner;

class Tester{
    public static void main(String[] args){
	System.out.println("Input the array:");
	Scanner sc = new Scanner(System.in);
	String[] segments = sc.nextLine().split(" ");
	int[] nums = new int[segments.length];
	for(int i = 0; i < segments.length; i++){
	    nums[i] = Integer.parseInt(segments[i]);
	}
	System.out.print("Input sum target: ");
	int k = sc.nextInt();
	System.out.println("The max length is " + Solution.maxSubArrayLen(nums, k));
    }
}