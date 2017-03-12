import java.util.Stack;

/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

public class BSTIterator {
    private Stack<TreeNode> nodes = new Stack<TreeNode>();
    
    public BSTIterator(TreeNode root) {
        TreeNode cur = root;
        while(cur != null){
            this.nodes.push(cur);
            cur = cur.left;
        }
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return !this.nodes.empty();
    }

    /** @return the next smallest number */
    public int next() {
        TreeNode cur = this.nodes.pop();
        int result = cur.val;
        cur = cur.right;
        while(cur != null){
            this.nodes.push(cur);
            cur = cur.left;
        }
        return result;
    }
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = new BSTIterator(root);
 * while (i.hasNext()) v[f()] = i.next();
 */