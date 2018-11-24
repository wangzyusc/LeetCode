#include "../../IOLib.hpp"

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == nullptr) return;
        //assume that it is a perfect binary tree
        if(root->left != nullptr)
            root->left->next = root->right;
        if(root->right != nullptr){
            if(root->next != nullptr){
                root->right->next = root->next->left;
            }
        }
        connect(root->left);
        connect(root->right);
    }
};
