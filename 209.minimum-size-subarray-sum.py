#
# @lc app=leetcode id=209 lang=python
#
# [209] Minimum Size Subarray Sum
#

# @lc code=start
class Solution(object):
    def minSubArrayLen(self, target, nums):
        # O(n^2)
        # O(n^2) number of all possible subarrays
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """
        # 2 3 1 2 4 3
        l = 0
        r = 0
        sum = 0
        minLen = float('inf')
        length = len(nums)
        while r < length:
            sum += nums[r]
            if sum >= target:
                minLen = min(minLen, r - l + 1)
                while l <= r and sum >= target:
                    minLen = min(minLen, r - l + 1)
                    sum -= nums[l]
                    l += 1
            r += 1
                
        return minLen if minLen != float('inf') else 0
        
# @lc code=end

