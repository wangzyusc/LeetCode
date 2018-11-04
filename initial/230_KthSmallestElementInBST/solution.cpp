#include "../IOLib.hpp"

/***
This is the recursive version of DFS.
Could also be done by iterative way.
Or binary search.
Time: O(n)
Space: O(height)
***/

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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return helper(root, k, count)->val;
    }
    TreeNode* helper(TreeNode* root, int k, int& count){
        TreeNode* l = NULL, *r = NULL;
        if(root->left) l = helper(root->left, k, count);
        if(l) return l;
        if(++count == k) return root;
        if(root->right) r = helper(root->right, k, count);
        return r;
    }
};
