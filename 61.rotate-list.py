#
# @lc app=leetcode id=61 lang=python3
#
# [61] Rotate List
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head:
            return head
        if not head.next:
            return head
        currNode = head
        count = 1
        while currNode.next:
            count += 1
            currNode = currNode.next
        currNode.next = head
        
        currNode = head
        k = k % count
        for i in range(0, count - k - 1):
            currNode = currNode.next
        head = currNode.next
        currNode.next = None
        return head
    
# @lc code=end

