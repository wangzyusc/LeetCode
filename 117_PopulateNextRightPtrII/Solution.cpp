#include "../IOLib.hpp"

/**
 * Definition for binary tree with next pointer.
 */

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        TreeLinkNode* ptr = root;
        TreeLinkNode* tmp = NULL;
        while((ptr = findNextWithChild(ptr)) != NULL){
            tmp = ptr;
            while(tmp){
                auto next = findNextWithChild(tmp->next);
                if(tmp->left){
                    TreeLinkNode* cur = tmp->left;
                    if(tmp->right){
                        tmp->left->next = tmp->right;
                        cur = tmp->right;
                    }
                    if(next && next->left) cur->next = next->left;
                    else if(next) cur->next = next->right;
                }
                else if(next){//tmp->right
                    if(next->left) tmp->right->next = next->left;
                    else tmp->right->next = next->right;
                }
                tmp = next;
            }
            ptr = (ptr->left != NULL) ? (ptr->left) : (ptr->right);
        }
    }
    TreeLinkNode* findNextWithChild(TreeLinkNode* root){
        while(root &&
              root->left == NULL &&
              root->right == NULL)
            root = root->next;
        return root;
    }
};

int main(void){
    return 0;
}
