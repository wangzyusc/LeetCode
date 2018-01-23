#include "../IOLib.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* Slow recursive version */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& preorder, int pre_l, int pre_r,
                        vector<int>& inorder, int in_l, int in_r) {
        if(pre_l > pre_r) return NULL;
        if(pre_l == pre_r) return new TreeNode(preorder[pre_l]);
        TreeNode* root = new TreeNode(preorder[pre_l]);
        int i = in_l;
        for(; inorder[i] != preorder[pre_l]; i++){}
        root->left = buildTree(preorder, pre_l + 1, i - in_l + pre_l, inorder, in_l, i - 1);
        root->right = buildTree(preorder, i - in_l + pre_l + 1, pre_r, inorder, i + 1, in_r);
        return root;
    }
};

/* Or could accelerate the search in line #24 by using a hashmap storing (number, index) pairs. */

/* There's another recursive version even more concise not understood yet.
 * The code is here:
class Solution {
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int& p, int& i, TreeNode* stop) {
        if (i < inorder.size() and (stop == NULL or inorder[i] != stop->val)) {
            TreeNode* ret = new TreeNode(preorder[p++]);
            ret->left = dfs(preorder, inorder, p, i, ret);
            i++;
            ret->right = dfs(preorder, inorder, p, i, stop);
            return ret;
        }
        else
            return NULL;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int p = 0, i = 0;
        return dfs(preorder, inorder, p, i, NULL);
    }
}; 
*/
