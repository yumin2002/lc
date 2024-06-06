#
# @lc app=leetcode id=30 lang=python
#
# [30] Substring with Concatenation of All Words
#

# @lc code=start
# class Solution(object):
    # def findSubstring(self, s, words):
    #     """
    #     :type s: str
    #     :type words: List[str]
    #     :rtype: List[int]
    #     """
    #     str_length = len(words[0]) * len(words)
    #     word_length = len(words[0])
    #     result = []
    #     # for each substring starting at each index, we check if the string is concatoenated string
    #     for i in range(0, len(s) - str_length + 1):
    #         curr_str = s[i:i+str_length]
    #         print(curr_str)
    #         if self.isConcatonated(curr_str, words):
    #             result.append(i)
    #     return result


    # def isConcatonated(self, s, words):
    #     my_map = {}
    #     for word in words:
    #         if word not in my_map:
    #             my_map[word] = 1
    #         else:
    #             my_map[word] += 1
    #     i = 0
    #     while i < len(s):
    #         curr_str = s[i:i+len(words[0])]
    #         print(curr_str)
    #         print(my_map)
    #         if curr_str not in my_map:
    #             return False
    #         if my_map[curr_str] <= 0:
    #             return False
    #         my_map[curr_str] -= 1
    #         i += len(words[0])
    #     return True
class Solution(object):
    def findSubstring(self, s, words):
        n = len(s)
        k = len(words)
        word_length = len(words[0])
        substring_size = word_length * k
        word_count = {}
        for word in words:
            if word in word_count:
                word_count[word] += 1
            else:
                word_count[word] = 1

        def sliding_window(left):
            words_found = collections.defaultdict(int)
            words_used = 0
            excess_word = False

            # Do the same iteration pattern as the previous approach - iterate
            # word_length at a time, and at each iteration we focus on one word
            for right in range(left, n, word_length):
                if right + word_length > n:
                    break

                sub = s[right : right + word_length]
                if sub not in word_count:
                    # Mismatched word - reset the window
                    words_found = collections.defaultdict(int)
                    words_used = 0
                    excess_word = False
                    left = right + word_length  # Retry at the next index
                else:
                    # If we reached max window size or have an excess word
                    while right - left == substring_size or excess_word:
                        # Move the left bound over continously
                        leftmost_word = s[left : left + word_length]
                        left += word_length
                        words_found[leftmost_word] -= 1

                        if (
                            words_found[leftmost_word]
                            == word_count[leftmost_word]
                        ):
                            # This word was the excess word
                            excess_word = False
                        else:
                            # Otherwise we actually needed it
                            words_used -= 1

                    # Keep track of how many times this word occurs in the window
                    words_found[sub] += 1
                    if words_found[sub] <= word_count[sub]:
                        words_used += 1
                    else:
                        # Found too many instances already
                        excess_word = True

                    if words_used == k and not excess_word:
                        # Found a valid substring
                        answer.append(left)

        answer = []
        for i in range(word_length):
            sliding_window(i)

        return answer
# @lc code=end

