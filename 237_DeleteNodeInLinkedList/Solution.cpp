#include "../IOLib.hpp"

using namespace std;

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
    void deleteNode(ListNode* node) {
        ListNode* ptr = node->next;
        *node = *ptr;
        delete ptr;
    }
};

int main(void){
	ListNode* head = readLinkedList();
	cout << "Input a number that is a node in the linked list: (except the tail)" << endl;
	int val = readInt();
	cout << "Before deletion: " << endl;
	printLinkedList(head);
	ListNode* node = findListNode(head, val);
	Solution solution;
	solution.deleteNode(node);
	cout << "After deletion: " << endl;
	printLinkedList(head);
	return 0;
}