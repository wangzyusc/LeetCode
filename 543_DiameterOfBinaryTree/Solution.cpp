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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        auto p = dfs(root);
        return p.second;
    }
    //pair: first: max-depth, second: diameter of this tree
    pair<int, int> dfs(TreeNode* root){
        if(root == nullptr) return make_pair(0, 0);
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        return make_pair(max(left.first, right.first) + 1,
                         max(max(left.second, right.second), left.first + right.first));
    }
};

int main(void){
    return 0;
}
