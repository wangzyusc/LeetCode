#include "../IOLib.hpp"

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        vector<TreeNode*> node_stack;
        traverse(root, sum, node_stack, result);
        return result;
    }
    void traverse(TreeNode* root, int sum, vector<TreeNode*>& node_stack, vector<vector<int> >& result){
        if(root == NULL) return;
        node_stack.push_back(root);
        if(root->left == NULL && root->right == NULL){
            if(sum == root->val){
                vector<int> path;
                for(int i = 0; i < node_stack.size(); i++)
                    path.push_back(node_stack[i]->val);
                result.push_back(path);
            }
        }
        else{
            traverse(root->left, sum-root->val, node_stack, result);
            traverse(root->right, sum-root->val, node_stack, result);
        }
        node_stack.pop_back();        
    }
};

int main(void){
    TreeNode* root = readBinaryTree();
    int sum = readInt();
    Solution solution;
    vector<vector<int> > result = solution.pathSum(root, sum);
    printMatrix(result);
    return 0;
}
