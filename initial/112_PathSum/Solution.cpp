#include "../IOLib.hpp"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL) return root->val == sum;
        return hasPathSum(root->left, sum - root->val) || 
            hasPathSum(root->right, sum - root->val);
    }
};

int main(void){
    TreeNode* root = readBinaryTree();
    int sum = readInt();
    Solution solution;
    bool result = solution.hasPathSum(root, sum);
    cout << "The tree " << (result?"has":"doesn't have")
         << " path sum of " << sum << endl;
    return 0;
}
