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
        if(!l2) return l1;
        if(!l1) return l2;
        vector<int> nums1, nums2, nums;
        while(l1){
            nums1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2){
            nums2.push_back(l2->val);
            l2 = l2->next;
        }
        int carry = 0, i = nums1.size() - 1, j = nums2.size() - 1;
        while(i >= 0 || j >= 0 || carry){
            int digit = (i>=0?nums1[i]:0) + (j>=0?nums2[j]:0) + carry;
            nums.push_back(digit % 10);
            carry = digit / 10;
            i--; j--;
        }
        ListNode* head = nullptr, *cur = nullptr;
        for(auto n: nums){
            head = new ListNode(n);
            head->next = cur;
            cur = head;
        }
        return head;
    }
};

int main(void){
    ListNode* l1 = readLinkedList();
    ListNode* l2 = readLinkedList();
    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);
    printLinkedList(result);
    return 0;
}
