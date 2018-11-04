import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

class Tester{
    public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	System.out.println("Input the numbers in the tree by level:");
	String[] numStr = sc.nextLine().split(" ");
	int[] nums = new int[numStr.length];
	for(int i = 0; i < numStr.length; i++){
	    nums[i] = Integer.parseInt(numStr[i]);
	}
	TreeNode root = BuildBinaryTree(nums);
	BSTIterator it = new BSTIterator(root);
	while(it.hasNext()) System.out.print(it.next() + " ");
	System.out.println();
    }

    public static TreeNode BuildBinaryTree(int[] nums){
	if(nums.length == 0) return null;
	TreeNode root = new TreeNode(nums[0]);
	Queue<TreeNode> queue = new LinkedList<TreeNode>();
	queue.add(root);
	int i = 0;
	while(++i < nums.length){
	    TreeNode cur = queue.remove();
	    cur.left = new TreeNode(nums[i]);
	    queue.add(cur.left);
	    if(++i < nums.length){
		cur.right = new TreeNode(nums[i]);
		queue.add(cur.right);
	    }
	}
	return root;
    }
}