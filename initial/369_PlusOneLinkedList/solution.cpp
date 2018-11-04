#include "../IOLib.hpp"

/***
1.Reverse;
2.Plus one;
3.Reverse again.
Time: O(n)
Space: O(1)
---------------
Another smarter solution:
1.Add a dummy node to head;
2.Use two pointers;
3.Find (1) the last node not equal to 9 and (2) last node;
4.If last node is 9, then set (1) plus one, and every node after it to be 0.
If last node is not 9, just plus one to it.
Time: O(n)
Space: O(1)
***/

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
    ListNode* plusOne(ListNode* head) {
        head = reverse(head);
        int carry = 1, sum;
        ListNode* ptr = head, *last = nullptr;
        while(ptr){
            sum = ptr->val + carry;
            carry = sum / 10;
            ptr->val = sum % 10;
            if(carry == 0) break;
            last = ptr;
            ptr = ptr->next;
        }
        if(carry)
            last->next = new ListNode(carry);
        head = reverse(head);
        return head;
    }
    ListNode* reverse(ListNode* head){
        ListNode* next = head->next, *result = head;
        while(next){
            head->next = next->next;
            next->next = result;
            result = next;
            next = head->next;
        }
        return result;
    }
};
