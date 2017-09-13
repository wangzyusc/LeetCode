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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == nullptr || p == nullptr) return nullptr;
        //so now root and p both not null
        if(root->val <= p->val){//p->val >= root->val
            return inorderSuccessor(root->right, p);
        }
        else{
            TreeNode* res = inorderSuccessor(root->left, p);
            if(res == nullptr) res = root;
            return res;
        }
    }
};

int main(void){
    return 0;
}
