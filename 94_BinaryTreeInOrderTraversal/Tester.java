import java.util.List;

class Tester{
    public static void main(String[] args){
	TreeNode root = new TreeNode(1);
	root.right = new TreeNode(2);
	root.right.left = new TreeNode(3);
	List<Integer> list = Solution.inorderTraversal(root);
	for(int num: list){
	    System.out.print(num + " ");
	}
	System.out.println();
    }
}