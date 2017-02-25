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
  ListNode* oddEvenList(ListNode* head) {
    if(head == NULL || head->next == NULL || head->next->next == NULL) return head;
    ListNode* oddhead = NULL, *evenhead = NULL;
    ListNode* oddtail = NULL, *eventail = NULL;
    bool isodd = true;
    while(head != NULL){
      if(isodd){
	if(oddhead == NULL){
	  oddhead = head;
	  oddtail = head;
	}
	else{
	  oddtail->next = head;
	  oddtail = oddtail->next;
	}
      }
      else{
	if(evenhead == NULL){
	  evenhead = head;
	  eventail = head;
	}
	else{
	  eventail->next = head;
	  eventail = eventail->next;
	}
      }
      isodd = !isodd;
      head = head->next;
    }
    oddtail->next = evenhead;
    eventail->next = NULL;
    return oddhead;
  }
};

int main(void){
  ListNode* head = readLinkedList();
  Solution solution;
  head = solution.oddEvenList(head);
  printLinkedList(head);
  return 0;
}
