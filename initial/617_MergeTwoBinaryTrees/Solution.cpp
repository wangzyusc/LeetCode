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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 != nullptr && t2 != nullptr){
            TreeNode* t3 = new TreeNode(t1->val + t2->val);
            t3->left = mergeTrees(t1->left, t2->left);
            t3->right = mergeTrees(t1->right, t2->right);
            delete t1; delete t2;
            return t3;
        }
        else if(t1 != nullptr){//t2 == nullptr
            return t1;
        }
        else if(t2 != nullptr){
            return t2;
        }
        else{//t1 == t2 == nullptr
            return nullptr;
        }
    }
};

int main(void){
    TreeNode* t1 = readBinaryTree();
    TreeNode* t2 = readBinaryTree();
    Solution solution;
    TreeNode* res = solution.mergeTrees(t1, t2);
    printBinaryTree(res);
    return 0;
}
