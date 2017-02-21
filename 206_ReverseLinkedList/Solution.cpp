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
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    ListNode* ptr = head->next;
    ListNode* last = head;
    ListNode* next = NULL;
    last->next = NULL;
    while(ptr != NULL){
      next = ptr->next;
      ptr->next = last;
      last = ptr;
      ptr = next;
    }
    return last;
  }
};

int main(void){
  ListNode* head = readLinkedList();
  printLinkedList(head);
  Solution solution;
  ListNode* result = solution.reverseList(head);
  printLinkedList(result);
  return 0;
}
