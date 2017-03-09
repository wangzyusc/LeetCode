class Tester{
    public static void main(String[] args){
	int[] nums = {4,2,3,1,8,3,5,7};
	if(Solution.containsDuplicate(nums)){
	    System.out.println("The array contains duplicates!");
	}
	else
	    System.out.println("The array doesn't contain duplicate!");
    } 
}