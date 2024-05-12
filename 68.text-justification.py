#
# @lc app=leetcode id=68 lang=python
#
# [68] Text Justification
#

# @lc code=start
class Solution(object):
    # debug needed
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
            # print(words[i])
            length =  charlen + len(words[i]) + len(currLine)
            # print(length)
            if length <= maxWidth:
                currLine.append(words[i])
                charlen += len(words[i])
                i += 1
            else:
                raw.append(currLine)
                currLine = []
                charlen = 0
            # print(currLine)
        if len(currLine):
            raw.append(currLine)
        justified = []
        # print(raw)
        for i in range(len(raw)):
            # print('i{}'.format(i))
            # last line should be left-aligned
            line = raw[i]
            lineStr = ' '.join(line)
            numSpace = maxWidth - len(lineStr)
            if (i == len(raw) - 1):
                justified.append(' '.join(line) + ' '*numSpace)
                continue
            # print('lenght of line: {}'.format(len(line)))
            if(len(line) == 1):
                # print('last line space: {}'.format(numSpace))
                justified.append('{}{}'.format(line[0], ' ' * numSpace))
            else:
                # print(len(lineStr))
                left = numSpace % (len(line) - 1)
                leftSpace = numSpace // (len(line) - 1) + 2
                rightSpace = numSpace // (len(line) - 1) + 1
                # print('{} {} {}'.format(leftSpace, rightSpace, left))
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

