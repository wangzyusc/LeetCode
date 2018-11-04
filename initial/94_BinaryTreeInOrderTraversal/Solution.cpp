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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
    void traverse(TreeNode* root, vector<int>& nums){
        if(root == NULL) return;
        if(root->left != NULL) traverse(root->left, nums);
        nums.push_back(root->val);
        if(root->right != NULL) traverse(root->right, nums);
    }
};

int main(){
	TreeNode* root = readBinaryTree();
	Solution solution;
	vector<int> nums = solution.inorderTraversal(root);
	printVector(nums);
	return 0;
}