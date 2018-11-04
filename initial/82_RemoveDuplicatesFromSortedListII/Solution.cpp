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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* result = new ListNode(0), *prev = result;
        result->next = head;
        //ListNode* last = head;
        while(head){
            bool dup = false;
            while(head->next && head->next->val == head->val){
                //last = head;
                head = head->next;
                dup = true;
            }
            if(!dup) prev = head;
            head = head->next;
            prev->next = head;
        }
        return result->next;
    }
};

int main(void){
    ListNode* head = readLinkedList();
    Solution sol;
    head = sol.deleteDuplicates(head);
    printLinkedList(head);
    return 0;
}
