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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL) return NULL;
    if(root->val >= min(p->val, q->val) && root->val <= max(p->val, q->val)) return root;
    else if(root->val < min(p->val, q->val)) return lowestCommonAncestor(root->right, p, q);
    else return lowestCommonAncestor(root->left, p, q);
  }
};

int main(void){
  TreeNode* root = readBinaryTree();
  int pval = readInt();
  int qval = readInt();
  TreeNode *p = findNodeInBinaryTree(root, pval);
  TreeNode *q = findNodeInBinaryTree(root, qval);
  Solution solution;
  TreeNode* LCA = solution.lowestCommonAncestor(root, p, q);
  cout << "Lowest common ancestor is " << LCA->val << endl;
  return 0;
}
