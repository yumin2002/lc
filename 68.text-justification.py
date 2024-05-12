#
# @lc app=leetcode id=68 lang=python
#
# [68] Text Justification
#

# @lc code=start
class Solution(object):
    # debug completed
    # This question test if the candidates can write clean code in short time while addressing edge case
    # Me: got the correct solution
    # broke down the question into 
    # 1. figure out which words are on which line
    # 2. justify each line except the last line
    # need to define helper functions
    # need to speed up
    # need to write useful comments
    # need to write some test cases in advance to include edge cases
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        raw = []
        currLine = []
        charlen = 0
        i = 0
        while i < len(words):
            length =  charlen + len(words[i]) + len(currLine)
            if length <= maxWidth:
                currLine.append(words[i])
                charlen += len(words[i])
                i += 1
            else:
                raw.append(currLine)
                currLine = []
                charlen = 0
        if len(currLine):
            raw.append(currLine)
        justified = []
        for i in range(len(raw)):
            # last line should be left-aligned
            line = raw[i]
            lineStr = ' '.join(line)
            numSpace = maxWidth - len(lineStr)
            if (i == len(raw) - 1 or len(line) == 1):
                justified.append(' '.join(line) + ' '*numSpace)
                continue
            else:
                left = numSpace % (len(line) - 1)
                leftSpace = numSpace // (len(line) - 1) + 2
                rightSpace = numSpace // (len(line) - 1) + 1
                currStr = ''
                for i in range(len(line)):
                    word = line[i]
                    if i == len(line) - 1:
                        currStr += word
                    else:
                        space = leftSpace * ' ' if i < left else rightSpace * ' '
                        # print('{} {} {}'.format(space, left, i))
                        currStr += word + space
                justified.append(currStr)
        return justified
# @lc code=end

