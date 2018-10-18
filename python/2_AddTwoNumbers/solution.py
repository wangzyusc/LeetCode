# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = ListNode(0)
        p1, p2, p = l1, l2, head
        carry = 0
        while (p1 or p2) or carry != 0:
            carry += (p1.val if p1 else 0) + (p2.val if p2 else 0)
            p.next = ListNode(carry % 10)
            p1, p2, p = p1.next if p1 else None, p2.next if p2 else None, p.next
            carry /= 10
        return head.next
        
