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
    vector<TreeNode*> pathToP;
    findPathToNode(root, p, pathToP);
    for(int i = pathToP.size()-1; i >= 0; i--){
      if(isDescendentOf(pathToP, i, q)) return pathToP[i];
    }
    return root;
  }
  bool findPathToNode(TreeNode* root, TreeNode* p, vector<TreeNode*>& path){
    if(root == NULL) return false;
    path.push_back(root);
    if(root == p){
      return true;
    }
    if(root->left){
      if(findPathToNode(root->left, p, path)) return true;
    }
    if(root->right){
      if(findPathToNode(root->right, p, path)) return true;
    }
    path.pop_back();
    return false;
  }
  bool isDescendentOf(vector<TreeNode*> path, int pos, TreeNode* target){
    if(pos < path.size() - 1){
      if(path[pos]->left == path[pos+1])
	return contains(path[pos], target, false, true);
      else
	return contains(path[pos], target, true, false);
    }
    else{
      return contains(path[pos], target, true, true);
    }
  }
  bool contains(TreeNode* root, TreeNode* target, bool left, bool right){
    if(root == target) return true;
    bool inLeft = false, inRight = false;
    if(root->left != NULL && left){
      inLeft = contains(root->left, target, true, true);
    }
    if(inLeft) return true;
    if(root->right != NULL && right){
      inRight = contains(root->right, target, true, true);
    }
    if(inRight) return true;
    return false;
  }
};

int main(void){
  TreeNode* root = readBinaryTree();
  cout << "Read two target node values: ";
  int pval, qval;
  cin >> pval >> qval;
  TreeNode* p = findNodeInBinaryTree(root, pval);
  TreeNode* q = findNodeInBinaryTree(root, qval);
  Solution solution;
  TreeNode* result = solution.lowestCommonAncestor(root, p, q);
  cout << "The lowest common ancestor node value is " << result->val << endl;
  return 0;
}
