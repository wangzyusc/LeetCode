#include "../IOLib.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* Use two pointers in two linked lists, count the numbers
 * of elements in each one and align the pointers with same
 * distance to the end. Then iterate through and find the
 * earliest same node.
 * Time: O(m + n), Space: O(1)
 * Other solutions: Hashmap to store nodes, space: O(m)
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA, *ptr2 = headB;
        int count1 = 0, count2 = 0;
        while(ptr1){
            count1++;
            ptr1 = ptr1->next;
        }
        while(ptr2){
            count2++;
            ptr2 = ptr2->next;
        }
        ptr1 = headA, ptr2 = headB;
        while(count1 > count2){
            count1--;
            ptr1 = ptr1->next;
        }
        while(count2 > count1){
            count2--;
            ptr2 = ptr2->next;
        }
        while(count1-- > 0 && ptr1 != ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
};
