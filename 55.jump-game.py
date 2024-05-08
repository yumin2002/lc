#
# @lc app=leetcode id=55 lang=python
#
# [55] Jump Game
#

# @lc code=start
class Solution(object):
    # Explaination
    # whenever an index has the potential of jumping pass the leftmost index we marked as true,
    # we are able to jump to that certain index
    # Therefore, we only need to keep track of the leftmost index where we can possibly jump to the end of the array as we iterate backwards
    # if we can jump pass that index or jump to that index, we can get to the end of the array because when we jump to that index, we will be able to jump to the end of the array(that is just why we recorded it.)
    # Time complexity: DP solution O(n^2) GreedyO(n)
    # Space complexity: DP solution O(n) GreedyO(1)
    
    # optimization
    # Greedy
    def canJump(self, nums):
        left_most_can_jump = len(nums) - 1
        for i in range(len(nums) - 2, -1, -1):
            if nums[i] + i >= left_most_can_jump:
                left_most_can_jump = i
        return left_most_can_jump == 0
    
    # # DP solution
    # def canJump(self, nums):
    #     """
    #     :type nums: List[int]
    #     :rtype: bool
    #     """
    #     result = [False] * len(nums)
    #     result[len(nums) - 1] = True
    #     for i in range(len(nums) - 1, -1, -1):
    #         for j in range(i, min(i + nums[i] + 1, len(nums))):
    #             if result[j]:
    #                 result[i] = True
    #                 break
                
    #     print(result)
    #     return result[0]
    
    
# @lc code=end
