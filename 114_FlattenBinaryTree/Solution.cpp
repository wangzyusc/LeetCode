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
public:
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        vector<TreeNode*> list;
        preorder(root, list);
        for(int i = 0; i < list.size() - 1; i++){
            list[i]->left = nullptr;
            list[i]->right = list[i+1];
        }
        //list.back()->left = nullptr;
        //list.back()->right = nullptr;
    }
    void preorder(TreeNode* root, vector<TreeNode*>& list){
        if(root == nullptr) return;
        list.push_back(root);
        if(root->left) preorder(root->left, list);
        if(root->right) preorder(root->right, list);
    }
};

int main(void){
    return 0;
}
