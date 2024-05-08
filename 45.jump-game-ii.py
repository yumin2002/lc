#
# @lc app=leetcode id=45 lang=python
#
# [45] Jump Game II
#

# @lc code=start
# greedy:
# starting from the rightmost index
# find the leftmost index that can jump to current index 
# continuously update the current index until we reached the beginning of the array
class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        curr = len(nums) - 1
        count = 0
        while curr != 0:
            for i in range(0, curr):
                if i + nums[i] >= curr:
                    curr = i
                    count += 1
                    break
        return count
        
# @lc code=end

