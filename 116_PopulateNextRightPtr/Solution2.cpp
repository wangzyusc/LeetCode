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
        TreeLinkNode* ptr = root, *tmp = ptr;
        while(ptr->left){
            tmp = ptr;
            while(tmp){
                tmp->left->next = tmp->right;
                if(tmp->next){
                    tmp->right->next = tmp->next->left;
                }
                tmp = tmp->next;
            }
            ptr = ptr->left;
        }
    }
};

int main(){
    return 0;
}
