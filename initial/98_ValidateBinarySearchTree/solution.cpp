#include "../IOLib.hpp"

using namespace std;

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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }
    bool isValidBST(TreeNode* root, TreeNode* upbound, TreeNode* lowbound){
        if(!root) return true;
        if((upbound && root->val >= upbound->val) ||
           (lowbound && root->val <= lowbound->val)) return false;
        return isValidBST(root->left, root, lowbound) &&
            isValidBST(root->right, upbound, root);
    }
};

int main(){
    TreeNode* root = readBinaryTree();
    printBinaryTree(root);
    Solution sol;
    bool result = sol.isValidBST(root);
    cout << "The result is " << (result ? "true" : "false") << endl;
    return 0;
}
