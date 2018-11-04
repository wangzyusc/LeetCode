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
  bool hasCycle(ListNode *head) {
    ListNode* slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL){
      fast = fast->next->next;
      slow = slow->next;
      if(fast == slow) return true;
    }
    return false;
  }
};

int main(void){
  ListNode* head = readLinkedList();
  Solution solution;
  cout << "The linked list has " << (solution.hasCycle(head)?"":"no ") << "cycle" << endl;
  return 0;
}
