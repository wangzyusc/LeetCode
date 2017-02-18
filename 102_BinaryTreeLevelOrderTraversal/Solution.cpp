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
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > result;
        traverse(root, result, 0);
        return result;
    }
    void traverse(TreeNode* root, vector<vector<int> >& nums, int depth){
        if(root == NULL) return;
        if(nums.size() <= depth){
            nums.push_back(vector<int>(0));
        }
        nums[depth].push_back(root->val);
        if(root->left) traverse(root->left, nums, depth+1);
        if(root->right) traverse(root->right, nums, depth+1);
    }
};

/*
 * The solution is admitted by LeetCode system, but local result is wrong.
 */
int main(){
	TreeNode* root = readBinaryTree();
	Solution solution;
	vector<vector<int> > result = solution.levelOrder(root);
	cout << "The level order traversal of binary tree is:" << endl;
	printMatrix(result);
	return 0;
}