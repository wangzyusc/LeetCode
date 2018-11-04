#include "../IOLib.hpp"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct comparator{
  bool operator() (const ListNode* a, const ListNode* b) const
  {
    return a->val > b->val;
  }
};
class Solution {
public:
  ListNode* sortList(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    priority_queue<ListNode*, vector<ListNode*>, comparator> heap;
    while(head != NULL){
      heap.push(head);
      head = head->next;
    }
    ListNode* root = new ListNode(0);
    ListNode* ptr = root;
    while(!heap.empty()){
      ptr->next = heap.top();
      ptr = ptr->next;
      heap.pop();
    }
    ptr->next = NULL;
    ptr = root->next;
    delete root;
    return ptr;
  }
    
};

int main(void){
  ListNode* head = readLinkedList();
  Solution solution;
  head = solution.sortList(head);
  printLinkedList(head);
  return 0;
}
