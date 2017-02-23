#include "../IOLib.hpp"

using namespace std;

class Solution {
private:
  struct TreeNode{
    int length;
    vector<TreeNode*> children;
    TreeNode(int len){this->length = len;};
  };
public:
  int lengthLongestPath(string input) {
    int maxlength = 0;
    int length = input.size();
    int lastbreak = -1;
    int depth = 0;
    TreeNode* root = new TreeNode(0);
    for(int i = 0; i < length; i++){
      if(i == length-1 || input[i] == '\n'){
	//if(i < length - 1) i++;
	string current = (i == length - 1) ? input.substr(lastbreak+1, i - lastbreak) :
	  input.substr(lastbreak+1, i - lastbreak - 1);
	TreeNode* ptr = root;
	int d = 0;
	while(d++ < depth){
	  ptr = ptr->children[ptr->children.size()-1];
	}
	if(isFile(current)){
	  //when it's a file, only count length, don't push it into the tree
	  maxlength = max(maxlength, int(ptr->length + current.size()));
	}
	else{//not a file
	  ptr->children.push_back(new TreeNode(ptr->length + current.size() + 1));
	}
	depth = 0;
	lastbreak = i;
      }
      else if(input[i] == '\t'){
	//if(i < length - 1) i++;
	depth++;
	lastbreak = i;
      }
    }
    return maxlength;
  }
  bool isFile(string& s){
    for(int i = s.size()-2; i > 0; i--){
      if(s[i] == '.') return true;
    }
    return false;
  }
};

int main(void){
  string input = readString();
  Solution solution;
  cout << "Longest absolute path for it is " << solution.lengthLongestPath(input) << endl;
  return 0;
}
