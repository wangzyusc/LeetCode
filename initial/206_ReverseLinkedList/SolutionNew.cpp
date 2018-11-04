#include "../IOLib.hpp"

/**
This problem could be done iteratively or recursively.
**/

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
        ListNode *pre = head, *next = head->next;
        head->next = NULL;
        while(next){
            head = next;
            next = next->next;
            head->next = pre;
            pre = head;
        }
        return head;
    }
};

int main(void){
    ListNode* head = readLinkedList();
    Solution sol;
    printLinkedList(sol.reverseList(head));
    return 0;
}
