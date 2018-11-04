#include "../IOLib.hpp"

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
private:
    string arrow = "->";
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root == nullptr) return result;
        traverse(root, to_string(root->val), result);
        return result;
    }
    void traverse(TreeNode* root,
                  string path,
                  vector<string>& result){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            result.push_back(path);
            return;
        }
        if(root->left)
            traverse(root->left, path + arrow + to_string(root->left->val), result);
        if(root->right)
            traverse(root->right, path + arrow + to_string(root->right->val), result);
    }
};

int main(void){
    TreeNode* root = readBinaryTree();
    Solution solution;
    vector<string> result = solution.binaryTreePaths(root);
    printVectorOfStrings(result);
    return 0;
}
