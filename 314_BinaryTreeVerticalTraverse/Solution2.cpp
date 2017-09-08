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
        int pos;
        Node(TreeNode* srcnode, int val): node(srcnode), pos(val) {}
    };
public:
    vector<vector<int> > verticalOrder(TreeNode* root) {
        if(root == nullptr) return vector<vector<int> >();
        map<int, vector<int> > layers;
        queue<Node*> line;
        line.push(new Node(root, 0));
        while(!line.empty()){
            Node* current = line.front();
            line.pop();
            if(layers.find(current->pos) == layers.end())
                layers[current->pos] = vector<int>();
            layers[current->pos].push_back(current->node->val);
            if(current->node->left != nullptr)
                line.push(new Node(current->node->left, current->pos - 1));
            if(current->node->right != nullptr)
                line.push(new Node(current->node->right, current->pos + 1));
            delete current;
        }
        vector<vector<int> > result;
        for(map<int, vector<int> >::iterator it = layers.begin();
            it != layers.end(); it++){
            result.push_back(it->second);
        }
        return result;
    }
};

int main(void){
    TreeNode* root = readBinaryTree();
    Solution solution;
    vector<vector<int> > res = solution.verticalOrder(root);
    printMatrix(res);
    return 0;
}
