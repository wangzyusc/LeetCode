#include "../IOLib.hpp"

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int result = 0;
        traverse(root, result, false);
        return result;
    }
    void traverse(TreeNode* root, int& sum, bool isLeft){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            if(isLeft) sum += root->val;
            return;
        }
        if(root->left != NULL){
            traverse(root->left, sum, true);
        }
        if(root->right != NULL){
            traverse(root->right, sum, false);
        }
    }
};

int main(void){
    TreeNode* root = readBinaryTree();
    Solution solution;
    int result = solution.sumOfLeftLeaves(root);
    cout << "Sum of left leaves are " << result << endl;
    return 0;
}
