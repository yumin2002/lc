#
# @lc app=leetcode id=189 lang=python
#
# [189] Rotate Array
#

# @lc code=start
class Solution(object):
    
    
    
    # TODO: need retry 
    # space complexity O(1)
    # cyclic rotate until rotated n times
    def rotate(self, nums, k):
        n = len(nums)
        k %= n
        
        start = count = 0
        while count < n:
            current, prev = start, nums[start]
            while True:
                # need to understand this part
                next_idx = (current + k) % n
                nums[next_idx], prev = prev, nums[next_idx]
                current = next_idx
                count += 1
                
                if start == current:
                    break
            start += 1
        
    
    # # method 2: using reverse
    # # reverse: swaping 0--len, 1--(len-1), ... until all swapped
    # def reverse(self, nums: list, start: int, end: int) -> None:
    #     while start < end:
    #         nums[start], nums[end] = nums[end], nums[start]
    #         start, end = start + 1, end - 1
                
    # def rotate(self, nums: List[int], k: int) -> None:
    #     n = len(nums)
    #     k %= n

    #     self.reverse(nums, 0, n - 1)
    #     self.reverse(nums, 0, k - 1)
    #     self.reverse(nums, k, n - 1)
        
# @lc code=end

