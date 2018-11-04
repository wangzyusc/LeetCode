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
  TreeNode* invertTree(TreeNode* root) {
    if(root == NULL) return NULL;
    invertTree(root->left);
    invertTree(root->right);
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
  }
};

int main(void){
  TreeNode* root = readBinaryTree();
  printBinaryTree(root);
  Solution solution;
  solution.invertTree(root);
  printBinaryTree(root);
  return 0;
}
