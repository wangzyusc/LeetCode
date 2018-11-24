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
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        flatten(root->left);
        flatten(root->right);
        if(root->left){
            auto l = root->left, r = root->right;
            while(l->right){
                l = l->right;
            }
            root->right = root->left;
            root->left = nullptr;
            l->right = r;
        }
    }
};
