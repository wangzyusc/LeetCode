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
  bool isBalanced(TreeNode* root) {
    if(root == NULL) return true;
    int leftDepth, rightDepth;
    if((leftDepth = subtreeDepth(root->left)) == -1) return false;
    if((rightDepth = subtreeDepth(root->right)) == -1) return false;
    return abs(leftDepth - rightDepth) <= 1;
  }
  int subtreeDepth(TreeNode* root){
    if(root == NULL) return 0;
    int leftDepth = subtreeDepth(root->left);
    if(leftDepth == -1) return -1;
    int rightDepth = subtreeDepth(root->right);
    if(rightDepth == -1) return -1;
    if(abs(leftDepth - rightDepth) > 1) return -1;
    return max(leftDepth, rightDepth) + 1;
  }
};

int main(void){
  TreeNode* root = readBinaryTree();
  Solution solution;
  cout << "The binary tree is " << (solution.isBalanced(root)?"":"not ") << "balanced." << endl;
  return 0;
}
