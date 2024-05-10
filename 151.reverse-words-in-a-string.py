#
# @lc app=leetcode id=151 lang=python
#
# [151] Reverse Words in a String
#

# @lc code=start
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        return ' '.join(reversed(s.split()))
    
    # mutatble string:O(1)
    # reverse the whole string
    # remove leading white space
    # while ptr not at the end of the string:
    #   reverse the word
    #   while current ptr does not point to a character:
    #       remove extra white space by incrementing the reading pointer while keeping the writing pointer unchanged
    
    
# @lc code=end

