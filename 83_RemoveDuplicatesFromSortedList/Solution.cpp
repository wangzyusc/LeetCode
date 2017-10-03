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
        if(!head || !(head->next)) return head;
        ListNode* result = head;//new ListNode(0);
        //result->next = head;
        //ListNode* temp = NULL;
        while(head){
            while(head->next && head->next->val == head->val){
                //temp = head->next;
                head->next = head->next->next;
                //delete temp;
            }
            head = head->next;
        }
        //head = result->next;
        //delete result;
        return result;
    }
};

int main(void){
    ListNode* head = readLinkedList();
    Solution sol;
    head = sol.deleteDuplicates(head);
    printLinkedList(head);
    return 0;
}
