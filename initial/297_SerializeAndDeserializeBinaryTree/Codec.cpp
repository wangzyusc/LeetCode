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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        queue<TreeNode*> line;
        line.push(root);
        while(!line.empty()){
            TreeNode* cur = line.front();
            line.pop();
            if(cur == nullptr) result += ",null";
            else{
                result += ("," + to_string(cur->val));
                line.push(cur->left);
                line.push(cur->right);
            }
        }
        result[0] = '[';
        result += ']';
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data.substr(1, data.size()-2));
        vector<string> elements;
        string num;
        while(getline(ss, num, ',')){
            if(num.size() > 0) elements.push_back(num);
        }
        TreeNode* root = nullptr;
        queue<TreeNode**> line;
        line.push(&root);
        int pos = 0;
        while(pos < elements.size() && !line.empty()){
            TreeNode** cur = line.front();
            line.pop();
            if(elements[pos] == "null") *cur = nullptr;
            else{
                *cur = new TreeNode(stoi(elements[pos]));
                line.push(&((*cur)->left));
                line.push(&((*cur)->right));
            }
            pos++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(void){
    TreeNode* root = readBinaryTree();
    Codec codec;
    string str = codec.serialize(root);
    cout << str << endl;
    TreeNode* result = codec.deserialize(str);
    cout << "Result tree" << endl;
    printBinaryTree(result);
    return 0;
}
