import java.util.Scanner;

class Tester{
    public static void main(String[] args){
	System.out.println("Please input an array: ");
	Scanner sc = new Scanner(System.in);
	String line = sc.nextLine();
	String[] segments = line.split(" ");
	int[] nums = new int[segments.length];
	for(int i = 0; i < nums.length; i++){
	    nums[i] = Integer.parseInt(segments[i]);
	}
	NumArray db = new NumArray(nums);
	System.out.println("Please input sum range [i, j]:");
	line = sc.nextLine();
	segments = line.split(" ");
	int i = Integer.parseInt(segments[0]);
	int j = Integer.parseInt(segments[1]);
	System.out.println("The sum in range [" + i + ", " + j +"] is " + 
			   db.sumRange(i,j));
    }
}