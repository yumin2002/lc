#
# @lc app=leetcode id=68 lang=python
#
# [68] Text Justification
#

# @lc code=start
class Solution(object):
    # debug needed
    # def fullJustify(self, words, maxWidth):
    #     """
    #     :type words: List[str]
    #     :type maxWidth: int
    #     :rtype: List[str]
    #     """
    #     raw = []
    #     currLine = []
    #     currLen = 0
    #     i = 0
    #     while i < len(words):
    #         print(words[i])
    #         length =  currLen + len(words[i]) + 1 
    #         if length <= maxWidth:
    #             currLine.append(words[i])
    #             currLen = length
    #             i += 1
    #         else:
    #             raw.append(currLine)
    #             currLine = []
    #             currLen = 0
    #         # print(currLine)
    #     if len(currLine):
    #         raw.append(currLine)
    #     justified = []
    #     print(raw)
    #     for i in range(len(raw)):
    #         # last line should be left-aligned
    #         line = raw[i]
    #         if (i == len(raw) - 1):
    #             justified.append(' '.join(line))
    #             continue
            
    #         lineStr = ' '.join(line)
    #         numSpace = maxWidth - len(lineStr)
            
    #         if(len(line) == 1):
    #             justified.append(line[0] + ' ' * (numSpace))
    #         else:
    #             print(len(lineStr))
    #             left = numSpace % (len(line) - 1)
    #             leftSpace = numSpace // (len(line) - 1) + 2
    #             rightSpace = numSpace // (len(line) - 1) + 1
    #             print('{} {} {}'.format(leftSpace, rightSpace, left))
    #             currStr = ''
    #             for i in range(len(line)):
    #                 word = line[i]
    #                 if i == len(line) - 1:
    #                     currStr += word
    #                 else:
    #                     space = leftSpace * ' ' if i <= left else rightSpace * ' '
    #                     print('{} {} {}'.format(space, left, i))
    #                     currStr += word + space
    #             justified.append(currStr)
    #     return justified
# @lc code=end

