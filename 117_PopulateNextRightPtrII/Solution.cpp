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

/* Actually this problem could be reduced to a BFS problem... 
 * BFS traverses the tree level by level, so could connect each level in the queue.
 */
class Solution2 {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        queue<TreeLinkNode*> queue;
        queue.push(root);
        while(!queue.empty()){
            int len = queue.size();
            while(len-- > 0){
                auto curr = queue.front();
                queue.pop();
                curr->next = len ? queue.front() : NULL;
                if(curr->left) queue.push(curr->left);
                if(curr->right) queue.push(curr->right);
            }
        }
    }
};

int main(void){
    return 0;
}
