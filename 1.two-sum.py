#
# @lc app=leetcode id=1 lang=python
#
# [1] Two Sum
#

# @lc code=start
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        myMap = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in myMap:
                return [myMap[complement], i]
            else:
                myMap[num] = i
        return []
# @lc code=end

