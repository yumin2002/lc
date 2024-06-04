#
# @lc app=leetcode id=24 lang=python
#
# [24] Swap Nodes in Pairs
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return head
        currNode = head
        nextNode = head.next
        prevNode = None
        head = nextNode
        while currNode is not None and nextNode is not None:
            currNode.next = nextNode.next
            nextNode.next = currNode
            if (prevNode):
                prevNode.next = nextNode
            prevNode = currNode
            currNode = currNode.next
            nextNode = currNode.next if currNode is not None else None
        return head
        
# @lc code=end

