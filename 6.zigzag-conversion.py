#
# @lc app=leetcode id=6 lang=python
#
# [6] Zigzag Conversion
#

# @lc code=start
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        container = [[] for i in range(numRows)]
        cycle = numRows * 2 - 2
        for i in range(len(s)):
            # cycle is numRows * 2 - 2
            # i % cycle if going downwards
            # cycle - i % cycle if going upwards
            row = i % cycle if i % cycle < numRows else cycle - i % cycle
            container[row].append(s[i])

        res = ''
        for str in container:
            for character in str:
                res += character
        return res
# @lc code=end

