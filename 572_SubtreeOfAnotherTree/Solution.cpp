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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == nullptr){
            if(t == nullptr) return true;
            else return false;
        }
        if(t == nullptr) return false;
        //so now neither s nor t is null
        if(s->val == t->val){
            if(dfs(s->left, t->left) && dfs(s->right, t->right))
                return true;
        }
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool dfs(TreeNode* s, TreeNode* t){
        if(s == nullptr ^ t == nullptr) return false;
        if(s == nullptr && t == nullptr) return true;
        if(s->val != t->val) return false;
        return dfs(s->left, t->left) && dfs(s->right, t->right);
    }
};

int main(void){
    return 0;
}
