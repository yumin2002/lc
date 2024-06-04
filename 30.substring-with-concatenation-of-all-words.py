#
# @lc app=leetcode id=30 lang=python
#
# [30] Substring with Concatenation of All Words
#

# @lc code=start
class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        str_length = len(words[0]) * len(words)
        word_length = len(words[0])
        result = []
        # for each substring starting at each index, we check if the string is concatoenated string
        for i in range(0, len(s) - str_length + 1):
            curr_str = s[i:i+str_length]
            print(curr_str)
            if self.isConcatonated(curr_str, words):
                result.append(i)
        return result


    def isConcatonated(self, s, words):
        my_map = {}
        for word in words:
            if word not in my_map:
                my_map[word] = 1
            else:
                my_map[word] += 1
        i = 0
        while i < len(s):
            curr_str = s[i:i+len(words[0])]
            print(curr_str)
            print(my_map)
            if curr_str not in my_map:
                return False
            if my_map[curr_str] <= 0:
                return False
            my_map[curr_str] -= 1
            i += len(words[0])
        return True
        
# @lc code=end

