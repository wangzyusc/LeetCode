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
        vector<vector<TreeLinkNode*> > tree;
        dfs(root, tree, 0);
        for(auto layer: tree){
            for(int i = 0; i < layer.size() - 1; i++){
                layer[i]->next = layer[i + 1];
            }
        }
    }
    void dfs(TreeLinkNode* root, vector<vector<TreeLinkNode*> >& tree, int depth){
        if(root == NULL) return;
        if(tree.size() > depth){
            tree[depth].push_back(root);
        }
        else{
            tree.push_back(vector<TreeLinkNode*>(1, root));
        }
        dfs(root->left, tree, depth + 1);
        dfs(root->right, tree, depth + 1);
    }
};

int main(){
    return 0;
}
