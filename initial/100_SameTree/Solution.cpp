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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL || q == NULL) return (p == q);
    //else if(p == NULL || q == NULL) return false;
    //so now p != NULL and q != NULL
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};

int main(){
  //The build tree function is with problem. 
  TreeNode* p = readBinaryTree();
  TreeNode* q = readBinaryTree();
  printBinaryTree(p);
  printBinaryTree(q);
  Solution solution;
  bool same = solution.isSameTree(p, q);
  cout << "The two trees are " << (same ? "same" : "different") << "." << endl;
  return 0;
}
