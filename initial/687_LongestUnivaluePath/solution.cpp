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
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        if(root) dfs(root, res);
        return res;
    }
    //pair.first: inclusive for parent, pair.second: exclusive for parent
    int dfs(TreeNode* root, int& cross){
        int lres = (root->left)?dfs(root->left, cross):0;
        int rres = (root->right)?dfs(root->right, cross):0;
        if(root->left && root->val == root->left->val) lres++;
        else lres = 0;
        if(root->right && root->val == root->right->val) rres++;
        else rres = 0;
        cross = max(cross, lres + rres);
        return max(lres, rres);
    }
};
