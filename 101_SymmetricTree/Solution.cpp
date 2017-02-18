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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return compareSubtree(root->left, root->right);
    }
    bool compareSubtree(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL) return left == right;
        if(left->val != right->val) return false;
        return compareSubtree(left->left, right->right) && compareSubtree(left->right, right->left);
    }
};

int main(){
	TreeNode* root = readBinaryTree();
	Solution solution;
	cout << "This tree is ";
	if(!solution.isSymmetric(root)) cout << "not ";
	cout << "symmetric." << endl;
}