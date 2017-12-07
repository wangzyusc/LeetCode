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
  ListNode* swapPairs(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    ListNode* root = new ListNode(0);
    root->next = head;
    ListNode* ptr = root, *temp = NULL;
    while(ptr->next != NULL && ptr->next->next != NULL){
      temp = ptr->next->next;
      ptr->next->next = temp->next;
      temp->next = ptr->next;
      ptr->next = temp;
      ptr = ptr->next->next;
    }
    return root->next;
  }
};

/***
Another simpler swap method, no other temp variables.
***/
class Solution2 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode tmphead(0), *last = &tmphead;
        tmphead.next = head;
        while(head && head->next){
            last->next = head->next;
            last = head;
            head = head->next->next;
            last->next->next = last;
            last->next = head;
        }
        return tmphead.next;
    }
};

int main(void){
    ListNode* head = readLinkedList();
    Solution solution;
    ListNode* result = solution.swapPairs(head);
    viewLinkedList(result);
    return 0;
}
