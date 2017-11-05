#include "../IOLib.hpp"

/***
Binary search in BST.
Time: O(height) = O(log(n))
Space: O(1)
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
    int closestValue(TreeNode* root, double target) {
        TreeNode* cur = root;
        int res = root->val;
        double dist = abs(root->val - target);
        while(dist > 0 && cur){
            if(abs(cur->val - target) < dist){
                dist = abs(cur->val - target);
                res = cur->val;
            }
            if(target < cur->val)
                cur = cur->left;
            else
                cur = cur->right;
        }
        return res;
    }
};
