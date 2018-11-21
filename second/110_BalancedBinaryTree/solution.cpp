#include "../../IOLib.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int depth;
        return isBalanced(root, 1, depth);
    }
    bool isBalanced(TreeNode* root, int cur_depth, int& depth){
        if(root == NULL) return true;
        int l_dep = cur_depth, r_dep = cur_depth;
        ++cur_depth;
        if(root->left && !isBalanced(root->left, cur_depth, l_dep)) return false;
        if(root->right && !isBalanced(root->right, cur_depth, r_dep)) return false;
        if((l_dep > r_dep + 1) || (r_dep > l_dep + 1)) return false;
        depth = max(l_dep, r_dep);
        return true;
    }
};
