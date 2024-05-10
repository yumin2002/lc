#
# @lc app=leetcode id=402 lang=python
#
# [402] Remove K Digits
#

# @lc code=start
class Solution:
    # TODO: retry needed
    def removeKdigits(self, num, k):
        monotonic_stack = []
        for digit in num:
            while k and monotonic_stack and int(digit) < int(monotonic_stack[-1]):
                monotonic_stack.pop()
                k -= 1
            monotonic_stack.append(digit)
            finalStack = monotonic_stack[:-k] if k else monotonic_stack
        return ''.join(finalStack).lstrip('0') or '0'
    
    # monotonic stack: maintain an order in the stack while pushing elements in. Usually just discard the element out of order (the one read in or the on of the top of the stack)
    # each time we read in a digit, we have two option regarding the digits before it:
    #  1. keep it
    #  2. remove it
    # when we read in a digit, while there is still remaining digits to remove, we remove any digits before the read in digit that is bigger.
    # A digit before that is larger than the current digit will only make the result number larger. In another word, take the current digit intead will generate the smaller number. (Given that the resulting number are of the same length)
    # we can squash the previous 
    # def removeKdigits(self, num, k):
    #     numStack = []
        
    #     # Construct a monotone increasing sequence of digits
    #     for digit in num:
    #         while k and numStack and numStack[-1] > digit:
    #             numStack.pop()
    #             k -= 1
        
    #         numStack.append(digit)
        
    #     # - Trunk the remaining K digits at the end
    #     # - in the case k==0: return the entire list
    #     finalStack = numStack[:-k] if k else numStack
        
    #     # trip the leading zeros
    #     return "".join(finalStack).lstrip('0') or "0"
        
# @lc code=end

