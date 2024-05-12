#
# @lc app=leetcode id=167 lang=python
#
# [167] Two Sum II - Input Array Is Sorted
#

# @lc code=start
class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        # Explaination
        # Invariant: The solution to the problem (i.e., the indices l and r such that numbers[l] + numbers[r] = target) always lies between the current values of the pointers l and r.
        # Initialization: Initially, l is at the lowest index (0) and r is at the highest index (len(numbers) - 1). The entire array is between them, so if a solution exists, it must be between l and r.
        # Maintenance: When currSum < target, we increment l. Since the array is sorted in non-decreasing order, incrementing l will result in a larger currSum, thus helping it move closer to target. Conversely, when currSum > target, we decrement r. Decrementing r results in a smaller currSum, also moving it closer to target. By adjusting l and r this way, if a solution exists, it must still be between the updated values of l and r.
        # Termination: The loop stops when l meets or crosses r. By the invariant, as long as l < r, if there is a solution, it must be between l and r. Therefore, once they meet or cross, every possible pair has been tested while maintaining the invariant, thus ensuring that all pairs were correctly evaluated.
        # test cases
        # in: [1, 2, 3] 4
        # out: [1, 3]
        # in: [1, 2, 2] 4
        # out: [2, 3]
        # in: [1, 2, 2] 3
        # out: [1, 2] or [1, 3]
        
        l = 0
        r = len(numbers) - 1
        while l < r:
            currSum = numbers[l] + numbers[r]
            if currSum == target:
                return [l+1, r+1]
            if currSum < target:
                l += 1
            else:
                r -= 1
        return [-1, -1]
        
# @lc code=end

