#
# @lc app=leetcode id=15 lang=python
#
# [15] 3Sum
#

# @lc code=start
class Solution(object):
    # No sort solution using SET(optimized)
    # seen check if the complement is from the current iteratring
    # dup for optimization removes a subset of duplicates 
    # def threeSum(self, nums):
    #     # need to redo
    #     """
    #     :type nums: List[int]
    #     :rtype: List[List[int]]
    #     """
    #     res, dups = set(), set()
    #     seen = {}
    #     for i, val1 in enumerate(nums):
    #         if val1 not in dups:
    #             dups.add(val1)
    #             for j, val2 in enumerate(nums[i + 1 :]):
    #                 complement = -val1 - val2
    #                 if complement in seen and seen[complement] == i:
    #                     # duplicate removal
    #                     # prevent the following duplicates:
    #                     # -------
    #                     # [-1,0,1,2,-1,-4]
    #                     #     --------
    #                     # After you fix the start and end there can be an overlap
    #                     res.add(tuple((val1, val2, complement)))
    #                 seen[val2] = i
    #     return res
    
    
    # sort + two ptr
    def threeSum(self, nums):
        res = []
        nums.sort()
        for i in range(len(nums)):
            # if all the remaining are possitive, we cannot find a pair after the current index that sums to 0
            if nums[i] > 0:
                break
            # if nums[i - 1] == nums[i], the two sum will get the same result for nums[i-1] and nums[i]
            if i == 0 or nums[i - 1] != nums[i]:
                self.twoSumII(nums, i, res)
        return res

    def twoSumII(self, nums, i, res):
        lo, hi = i + 1, len(nums) - 1
        while lo < hi:
            sum = nums[i] + nums[lo] + nums[hi]
            if sum < 0:
                lo += 1
            elif sum > 0:
                hi -= 1
            else:
                res.append([nums[i], nums[lo], nums[hi]])
                lo += 1
                hi -= 1
                while lo < hi and nums[lo] == nums[lo - 1]:
                    lo += 1
# @lc code=end

