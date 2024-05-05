#
# @lc app=leetcode id=11 lang=python
#
# [11] Container With Most Water
#

# @lc code=start
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        i = 0
        j = len(height) - 1
        max_vol = 0
        while i < j:
            shorter_bar_index = i if height[i] < height[j] else j
            curr_vol = (j - i) * height[shorter_bar_index]
            max_vol = curr_vol if curr_vol > max_vol else max_vol
            if height[i] < height[j]:
                i += 1
            else:
                j -= 1
        return max_vol


# @lc code=end
