import java.util.List;
import java.util.ArrayList;
import java.util.Stack;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public static List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<Integer>();
        if(root == null) return list;
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode ptr = root;
        while(ptr != null || !stack.empty()){
            while(ptr != null){
                stack.push(ptr);
                ptr = ptr.left;
            }
            ptr = stack.pop();
            list.add(ptr.val);
            ptr = ptr.right;
        }
        return list;
    }
}