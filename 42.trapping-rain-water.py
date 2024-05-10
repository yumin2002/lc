#
# @lc app=leetcode id=42 lang=python
#
# [42] Trapping Rain Water
#

# @lc code=start
class Solution(object):
    # another bidirectional dp
    # the amount of water trapped at a specific index is determined by:
    # the shorter bar of the hightest bar on its left and the highest bar on its right
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if (len(height) <= 2):
            return 0
        left_highest = len(height) * [0]
        right_highest = len(height) * [0]
        for i in range(1, len(height)):
            left_highest[i] = height[i-1] if height[i-1] > left_highest[i-1] else left_highest[i-1]
            j = len(height) - 1 - i
            right_highest[j] = height[j+1] if height[j+1] > right_highest[j+1] else right_highest[j+1]
            
        water_trapped = 0
        for i in range(0, len(height)):
            water_trapped += max(0, min(left_highest[i], right_highest[i]) - height[i])
        return water_trapped
        
# @lc code=end

