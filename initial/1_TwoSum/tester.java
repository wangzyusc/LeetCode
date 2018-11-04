import java.util.Scanner;
import java.util.ArrayList;

public class tester{
    public static void main(String[] args){
	System.out.println("Input array data:");
	Scanner sc = new Scanner(System.in);
	ArrayList<Integer> arr = new ArrayList<Integer>();
	while(sc.hasNextInt()){
	    arr.add(sc.nextInt());
	}//this loop would not stop
	sc.next();
	System.out.println("Input target: ");
	int target = sc.nextInt();
	int[] nums = new int[arr.size()];
	for(int i = 0; i < arr.size(); i++){
	    nums[i] = arr.get(i);
	}
	int[] res = Solution.twoSum(nums, target);
	System.out.println("The result is: [" + res[0] + ", " + res[1] + "]");
    }
}