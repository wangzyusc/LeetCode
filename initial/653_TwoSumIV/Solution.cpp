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
    bool findTarget(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            int target = k - cur->val;
            if(target != cur->val && findNumber(root, target)){
                return true;
            }
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        return false;
    }
    bool findNumber(TreeNode* root, int k) {
        if(!root) return false;
        if(root->val == k) return true;
        if(k < root->val) return findNumber(root->left, k);
        return findNumber(root->right, k);
    }
};

int main(void){
    return 0;
}
