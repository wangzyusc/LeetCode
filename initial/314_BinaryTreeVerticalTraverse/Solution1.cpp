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
    vector<vector<int> > verticalOrder(TreeNode* root) {
        if(root == nullptr) return vector<vector<int> >();
        int left = 0, right = 0;
        probeDepth(root, 0, left, right);
        vector<vector<int> > result(right - left + 1, vector<int>());
        queue<TreeNode*> line;
        line.push(root);
        unordered_map<TreeNode*, int> ptr_to_pos;
        ptr_to_pos[root] = -left;
        while(!line.empty()){
            TreeNode* current = line.front();
            line.pop();
            int pos = ptr_to_pos[current];
            result[pos].push_back(current->val);
            if(current->left != nullptr){
                line.push(current->left);
                ptr_to_pos[current->left] = pos - 1;
            }
            if(current->right != nullptr){
                line.push(current->right);
                ptr_to_pos[current->right] = pos + 1;
            }
        }
        return result;
    }
    void probeDepth(const TreeNode* root, int loc, int& left, int& right){
        if(root == nullptr) return;
        if(loc < left) left = loc;
        else if(loc > right) right = loc;
        probeDepth(root->left, loc - 1, left, right);
        probeDepth(root->right, loc + 1, left, right);
    }
};

int main(void){
    TreeNode* root = readBinaryTree();
    Solution solution;
    vector<vector<int> > res = solution.verticalOrder(root);
    printMatrix(res);
    return 0;
}
