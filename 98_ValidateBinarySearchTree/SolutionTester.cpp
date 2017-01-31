#include "Solution.h"

using namespace std;

int main(){
	cout << "First test viewBinaryTree (answer should be [2 1 3]): " << endl;
	TreeNode* t1 = new TreeNode(1);
	t1->left = new TreeNode(2);
	t1->right = new TreeNode(3);
	viewBinaryTree(t1);
    TreeNode* root = readBinaryTree();
    viewBinaryTree(root);
    Solution solution;
    bool result = solution.isValidBST(root);
    cout << "The result is " << (result?"true":"false") << endl;
    return 0;
}