import java.util.List;

class Tester{
    public static void main(String[] args){
	TreeNode root = new TreeNode(7);
	root.left = new TreeNode(4);
	root.right = new TreeNode(11);
	root.left.left = new TreeNode(1);
	root.left.right = new TreeNode(6);
	root.right.left = new TreeNode(9);
	root.right.right = new TreeNode(16);
	List<Integer> list = Solution.preorderTraversal(root);
	System.out.println("The result should be: 7 4 1 6 11 9 16");
	for(int num : list){
	    System.out.print(num + " ");
	}
	System.out.println();
    }
}