#include <iostream>
#include <string>
#include <sstream>

using namespace std;


 /* Definition for singly-linked list.
  */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head == NULL) return head;
    ListNode* root = new ListNode(0);
    root->next = head;
    ListNode* left = root, *right = root;
    /*while(right->next != NULL && i < n){
            right = right->next;
            i++;
	    }*/
    for(int i = 0; i < n; i++){
      right = right->next;
    }
    while(right->next != NULL){
      right = right->next;
      left = left->next;
    }
    left->next = left->next->next;
    return root->next;
  }
};

int main(void){
    string line;
    int num, n;
    cout << "Input number elements in linked list:" << endl;
    getline(cin, line);
    cout << "Input number n: ";
    cin >> n;
    istringstream stream(line);
    ListNode* root = new ListNode(0), *ptr = root;
    while(stream >> num){
        ptr->next = new ListNode(num);
	    ptr = ptr->next;
    }
    Solution solution;
    ListNode* result = solution.removeNthFromEnd(root->next, n);
    cout << "After deletion:" << endl << "[";
    ptr = result;
    while(ptr != NULL){
        cout << ptr->val;
	if(ptr->next != NULL){
	  cout << ", ";
	}
	ptr = ptr->next;
    }
    cout << "]" << endl;
    return 0;
}
