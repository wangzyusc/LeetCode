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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* root = new ListNode(0), *temp = NULL;
        root->next = head;
        head = root;
        while(head->next){
            if(head->next->val == val){
                temp = head->next;
                head->next = temp->next;
                delete temp;
            }
            else head = head->next;
        }
        head = root->next;
        delete root;
        return head;
    }
};

int main(void){
    ListNode* head = readLinkedList();
    int val = readInt();
    Solution sol;
    head = sol.removeElements(head, val);
    printLinkedList(head);
    deleteLinkedList(head);
    return 0;
}
