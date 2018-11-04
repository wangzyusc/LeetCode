#include "../IOLib.hpp"

/**
 * It's correct to do this thing recursively, but a top-down approach might
 * be better than bottom-up approach.
 * Time: O(n)
 * Space: O(height)
**/

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
    int longestConsecutive(TreeNode* root) {
        if(root == nullptr) return 0;
        auto p = helper(root);
        return max(p.first, p.second);
    }
    //pair.first: inclusive, pair.second: exclusive
    pair<int, int> helper(TreeNode* root){
        if(root == nullptr) return make_pair(0, 0);
        if(!root->left && !root->right) return make_pair(1, 1);
        pair<int, int> leftres = make_pair(0, 0), rightres = make_pair(0, 0);
        pair<int, int> res = make_pair(1, 0);
        if(root->left){
            leftres = helper(root->left);
            if(root->left->val == root->val + 1){
                res.first = max(res.first, leftres.first + 1);
            }
            else res.second = max(res.second, leftres.first);
        }
        if(root->right){
            rightres = helper(root->right);
            if(root->right->val == root->val + 1){
                res.first = max(res.first, rightres.first + 1);
            }
            else res.second = max(res.second, rightres.first);
        }
        res.second = max(res.second, max(leftres.second, rightres.second));
        return res;
    }
};

/* Here is the top-down approach, much more clear */
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if(root == nullptr) return 0;
        int longest = 0;
        dfs(root, root->val, 1, longest);
        return longest;
    }
    void dfs(TreeNode* root, int parent, int curlen, int& longest){
        if(root->val == parent + 1) curlen++;
        else curlen = 1;
        longest = max(longest, curlen);
        if(root->left) dfs(root->left, root->val, curlen, longest);
        if(root->right) dfs(root->right, root->val, curlen, longest);
    }
};
