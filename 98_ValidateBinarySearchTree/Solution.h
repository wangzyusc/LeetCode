#include "../IOLib.hpp"

using namespace std;

class Solution{
public:
	bool isValidBST(TreeNode* root) {
    if(root == NULL || (root->left == NULL && root->right == NULL)) return true;
    vector<int> result = maxmin(root);
    if(result.size() == 2) return true;
    return false;
  }
    
  vector<int> maxmin(TreeNode* root){
    vector<int> result;
    if(root == NULL) return result;
    if(root->left == NULL && root->right == NULL){
      result.push_back(root->val);
      result.push_back(root->val);
      return result;
    }
    vector<int> leftres = maxmin(root->left);
    vector<int> rightres = maxmin(root->right);
    if(root->left != NULL){
      if(leftres.size() < 2 || leftres[0] >= root->val || leftres[1] >= root->val) return result;
      result.push_back(leftres[0]);
    }
    else result.push_back(root->val);
    if(root->right != NULL){
      if(rightres.size() < 2 || rightres[0] <= root->val || rightres[1] <= root->val) return result;
      result.push_back(rightres[1]);
    }
    else result.push_back(root->val);
    return result;
  }
};