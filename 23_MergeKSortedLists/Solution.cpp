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
struct comparator{
  bool operator()(ListNode* i, ListNode* j){
    return i->val > j->val;
  }
}; 
 
class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    int k = lists.size();
    if(k == 0) return NULL;
    ListNode* head = new ListNode(0), *ptr = head;
    priority_queue<int, vector<ListNode*>, comparator> minHeap;
    for(int i = 0; i < k; i++){
      if(lists[i] != NULL) minHeap.push(lists[i]);
    }
    while(!minHeap.empty()){
      ptr->next = minHeap.top();
      ptr = ptr->next;
      minHeap.pop();
      if(ptr->next != NULL) minHeap.push(ptr->next);
    }
    return head->next;
  }
};

int main(){
  int k = readInt();
  vector<ListNode*> lists;
  string line;
  getline(cin, line);
  for(int i = 0; i < k; i++){
    lists.push_back(readLinkedList());
  }
  Solution solution;
  ListNode* result = solution.mergeKLists(lists);
  printLinkedList(result);
  return 0;
}
