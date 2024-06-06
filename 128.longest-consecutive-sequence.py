#
# @lc app=leetcode id=128 lang=python3
#
# [128] Longest Consecutive Sequence
#

# @lc code=start
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numSet = set(nums)
        longest_streak = 0
        for num in numSet:
            if num - 1 not in numSet:
                currNum = num
                curr_streak = 1
                while currNum + 1 in numSet:
                    curr_streak += 1
                    currNum += 1
                longest_streak = max(longest_streak, curr_streak)
        return longest_streak
# @lc code=end

