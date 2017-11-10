#include "../IOLib.hpp"

/***
My own solution uses a hashmap to record the # for each
number in BST.
Time: O(n)
Space: O(n)
The solution with O(1) space complexity is Morris traverse.
***/

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
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        dfs(root);
        for(auto it: dict)
            if(it.second == maxcount) result.push_back(it.first);
        return result;
    }
    void dfs(TreeNode* root){
        if(!root) return;
        if(++dict[root->val] > maxcount) maxcount = dict[root->val];
        dfs(root->left);
        dfs(root->right);
    }
    unordered_map<int, int> dict;
    int maxcount;
};
