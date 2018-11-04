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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL || root->right == NULL){
            if(root->left != NULL) return minDepth(root->left)+1;
            if(root->right != NULL) return minDepth(root->right)+1;
        }
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

int main(){
	TreeNode* root = readBinaryTree();
	Solution solution;
	cout << "The minimum depth of this tree is " << solution.minDepth(root) << "." << endl;
	return 0;
}