#
# @lc app=leetcode id=238 lang=python
#
# [238] Product of Array Except Self
#

# @lc code=start
class Solution(object):
    # optimizaiton:
    # space complexity O(1)
    # output array does not count
    # [1,2,3,4]
    # []
    #  calculate prefix and store it in the result array
    #  calculate postfix by storing the previous result in a variable and direclty multiply the current result and the value at the corresponding index of the result array
    def productExceptSelf(self, nums):
        result = [1] * len(nums)
        for i in range(1, len(result)):
            result[i] = result[i-1] * nums[i-1]
        temp = 1
        for i in range(len(nums) - 2, -1, -1):
            result[i] = result[i] * temp * nums[i+1]
            temp = temp * nums[i+1]
        return result
    
    
    
    # # Time complexity: O(n)
    # # Space complexity: O(n)
    # # keep bidirection dp memo
    # # prefix: compute the prefix multiplication before index i
    # # postfix: compute the postfix multiplication after index i
    # def productExceptSelf(self, nums):
    #     """
    #     :type nums: List[int]
    #     :rtype: List[int]
    #     """
    #     prefix = [1] * len(nums)
    #     postfix = [1] * len(nums)
    #     for pre_ptr in range(1, len(nums)):
    #         prefix[pre_ptr] = prefix[pre_ptr - 1] * nums[pre_ptr - 1]
    #         post_prt = len(nums) - pre_ptr - 1
    #         postfix[post_prt] = postfix[post_prt + 1] * nums[post_prt + 1]
        
    #     for i in range(0, len(nums)):
    #         nums[i] = prefix[i]*postfix[i]
    #     return nums
# @lc code=end

