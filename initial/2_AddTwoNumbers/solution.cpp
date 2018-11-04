#include "../IOLib.hpp"

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2) return l1 ? l1 : l2;
        ListNode* head = new ListNode(0), *ptr = head;
        int carry = 0;
        while(l1 || l2 || carry){
            int sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;
            carry = sum / 10;
            sum %= 10;
            ptr = (ptr->next = new ListNode(sum));
            //ptr = ptr->next;
            l1 = l1?l1->next:l1;
            l2 = l2?l2->next:l2;
        }
        return head->next;
    }
};
