#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* result = new ListNode(0);
    ListNode* ptr = result;
    while(l1 != NULL && l2 != NULL){
      if(l1->val <= l2->val){
	ptr->next = l1;
	l1 = l1->next;
      }
      else{
	ptr->next = l2;
	l2 = l2->next;
      }
      ptr = ptr->next;
    }
    if(l1 != NULL){
      ptr->next = l1;
      //l1 = l1->next
    }
    if(l2 != NULL){
      ptr->next = l2;
    }
    return result->next;
  }
};

int main(void){
    ListNode* head1 = new ListNode(0);
    ListNode* head2 = new ListNode(0);
    ListNode* ptr1 = head1, * ptr2 = head2;
    cout << "Input numbers in list 1: " << endl;
    string line;
    int num;
    getline(cin, line);
    istringstream stream1(line);
    while(stream1 >> num){
        ptr1->next = new ListNode(num);
	ptr1 = ptr1->next;
    }
    cout << "Input numbers in list 2: " << endl;
    getline(cin, line);
    istringstream stream2(line);
    while(stream2 >> num){
        ptr2->next = new ListNode(num);
	ptr2 = ptr2->next;
    }
    Solution solution;
    ListNode* result = solution.mergeTwoLists(head1->next, head2->next);
    cout << "The result is:" << endl << "[";
    while(result != NULL){
        cout << result->val;
	if(result->next != NULL) cout << ", ";
	else cout << "]" << endl;
	result = result->next;
    }
    return 0;
}
