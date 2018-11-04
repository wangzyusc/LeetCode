#include "../IOLib.hpp"

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
/* Solution using hashmap */
/* time: O(n), Space: O(n) */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return head;
        RandomListNode* ptr = head, *last = new RandomListNode(head->label);
        unordered_map<int, RandomListNode*> hash;
        hash[head->label] = last;
        while(ptr->next){
            RandomListNode* temp = new RandomListNode(ptr->next->label);
            hash[ptr->next->label] = temp;
            last->next = temp;
            last = temp;
            ptr = ptr->next;
        }
        ptr = head;
        while(ptr){
            auto temp = hash[ptr->label];
            if(ptr->random) temp->random = hash[ptr->random->label];
            ptr = ptr->next;
        }
        return hash[head->label];
    }
};

/* There're other solutions without using hashmap */
