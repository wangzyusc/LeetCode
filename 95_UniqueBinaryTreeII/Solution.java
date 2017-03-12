import java.util.List;
import java.util.LinkedList;

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
    public List<TreeNode> generateTrees(int n) {
        LinkedList<TreeNode> zero = new LinkedList<TreeNode>();
        if(n == 0) return zero;
        zero.add(null);
        LinkedList<TreeNode> one = new LinkedList<TreeNode>();
        one.add(new TreeNode(1));
        if(n == 1) return one;
        List<LinkedList<TreeNode>> group = new LinkedList<LinkedList<TreeNode>>();
        group.add(zero);
        group.add(one);
        for(int i = 2; i <= n; i++){
            LinkedList<TreeNode> list = new LinkedList<TreeNode>();
            for(int j = 1; j <= i; j++){
                for(TreeNode left : group.get(j-1)){
                    for(TreeNode right : group.get(i-j)){
                        TreeNode root = new TreeNode(j);
                        root.left = copyStructure(left, 0);
                        root.right = copyStructure(right, j);
                        list.add(root);
                    }
                }
            }
            group.add(list);
        }
        return group.get(n);
    }
    
    public TreeNode copyStructure(TreeNode src, int bias){
        if(src == null) return null;
        TreeNode root = new TreeNode(src.val + bias);
        root.left = copyStructure(src.left, bias);
        root.right = copyStructure(src.right, bias);
        return root;
    }
}