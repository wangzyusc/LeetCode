#include "../../IOLib.hpp"

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode *p1 = l1, *p2 = l2, *ptr = head;
        while(p1 && p2){
            if(p1->val <= p2->val){
                ptr->next = p1;
                p1 = p1->next;
            }
            else{
                ptr->next = p2;
                p2 = p2->next;
            }
            ptr = ptr->next;
            ptr->next = nullptr;
        }
        if(p1) ptr->next = p1;
        if(p2) ptr->next = p2;
        return head->next;
    }
};
