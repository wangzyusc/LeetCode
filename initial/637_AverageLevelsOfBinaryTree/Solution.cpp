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
    struct Node{
        TreeNode* node;
        int depth;
        Node(TreeNode* node, int d) : node(node), depth(d) {}
    };
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr) return vector<double>();
        vector<double> level_sum;
        vector<int> level_count;
        queue<Node*> line;
        line.push(new Node(root, 0));
        while(!line.empty()){
            Node* cur = line.front();
            line.pop();
            if(cur->depth >= level_sum.size()){
                level_sum.push_back(cur->node->val);
                level_count.push_back(1);
            }
            else{
                level_sum[cur->depth] += cur->node->val;
                level_count[cur->depth]++;
            }
            if(cur->node->left != nullptr)
                line.push(new Node(cur->node->left, cur->depth + 1));
            if(cur->node->right != nullptr)
                line.push(new Node(cur->node->right, cur->depth + 1));
        }
        vector<double> result(level_sum.size());
        for(int i = 0; i < result.size(); i++)
            result[i] = level_sum[i]  / level_count[i];
        return result;
    }
};
