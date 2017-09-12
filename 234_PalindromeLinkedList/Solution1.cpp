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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        ListNode* slow = head, *fast = head;
        vector<int> first_half, second_half;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            first_half.push_back(slow->val);
            slow = slow->next;
        }
        while(slow != nullptr){
            second_half.push_back(slow->val);
            slow = slow->next;
        }
        auto it1 = first_half.begin();
        auto it2 = second_half.rbegin();
        for(; it1 != first_half.end() && it2 != second_half.rend(); it1++, it2++)
            if(*it1 != *it2) return false;
        return true;
    }
};

int main(void){
    ListNode* root = readLinkedList();
    Solution solution;
    bool res = solution.isPalindrome(root);
    cout << "The linked list is " << (res?"":"not ") << "palindrome." << endl;
    return 0;
}
