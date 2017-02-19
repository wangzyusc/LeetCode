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
  vector<vector<int> > levelOrderBottom(TreeNode* root) {
    vector<vector<int> > result;
    traverse(root, result, 0);
    return result;
  }
  void traverse(TreeNode* root, vector<vector<int> >& result, int depth){
    if(root == NULL) return;
    if(result.size() <= depth){
      result.insert(result.begin(), vector<int>(0));
    }
    result[result.size() - 1 - depth].push_back(root->val);
    traverse(root->left, result, depth + 1);
    traverse(root->right, result, depth + 1);
  }
};

int main(){
  TreeNode* root = readBinaryTree();
  Solution solution;
  vector<vector<int> > result = solution.levelOrderBottom(root);
  printMatrix(result);
  return 0;
}
