#
# @lc app=leetcode id=80 lang=python
#
# [80] Remove Duplicates from Sorted Array II
#

# @lc code=start
class Solution(object):
    
    # 05/07 redo
    # ptr is the rewrite ptr while count keeps track of whether the number of occurence of the current number exceeds the contraint of 2.
    # whenever the count is exceeded, we skip writing it to the original array
    # if the countr is within 2, we continue to rewrite
    def removeDuplicates(self, nums):
        count = 1
        ptr = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[i-1]:
                count = 1
            else:
                count += 1
            if count <= 2:
                nums[ptr] = nums[i]
                ptr += 1
        return ptr
                
    # TODO: retry needed
    # # My solution: keep 2 temp var recording the previous values
    # # used because I wanted to prevent the previous two values of the current ptr from being overriten
    # # can use a more efficient solution by using count
    # def removeDuplicates(self, nums):
    #     if len(nums) <= 2:
    #          return len(nums)
    #     length = len(nums)
    #     ptr = 2
    #     prev1 = nums[0]
    #     prev2 = nums[1]
    #     for i in range(2, length):
    #         if prev1 != nums[i]:
    #             prev1 = prev2
    #             prev2 = nums[i]
    #             nums[ptr] = nums[i]
    #             ptr += 1
    #         else:
    #             prev1 = prev2
    #             prev2 = nums[i]
        
    #     return ptr
    
    def removeDuplicates(self, nums):

        # Initialize the counter and the second pointer.
        j, count = 1, 1

        # Start from the second element of the array and process
        # elements one by one.
        for i in range(1, len(nums)):

            # If the current element is a duplicate,
            # increment the count.
            if nums[i] == nums[i - 1]:
                count += 1
            else:
                # Reset the count since we encountered a different element
                # than the previous one
                count = 1

            # For a count <= 2, we copy the element over thus
            # overwriting the element at index "j" in the array
            if count <= 2:
                nums[j] = nums[i]
                j += 1

        return j
        
# @lc code=end

