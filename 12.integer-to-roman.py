#
# @lc app=leetcode id=12 lang=python
#
# [12] Integer to Roman
#

# @lc code=start
class Solution(object):
    # 1. hardcode the subtractive form like "CM"
    # 2. try to fit the largest value in (by iterating through the digit list)
    # TODO: redo needed
    def intToRoman(self, num: int) -> str:
        digits = [
            (1000, "M"),
            (900, "CM"),
            (500, "D"),
            (400, "CD"),
            (100, "C"),
            (90, "XC"),
            (50, "L"),
            (40, "XL"),
            (10, "X"),
            (9, "IX"),
            (5, "V"),
            (4, "IV"),
            (1, "I"),
        ]

        roman_digits = []
        # Loop through each symbol.
        for value, symbol in digits:
            # We don't want to continue looping if we're done.
            if num == 0:
                break
            count, num = divmod(num, value)
            # Append "count" copies of "symbol" to roman_digits.
            roman_digits.append(symbol * count)
        return "".join(roman_digits)
    
    
    # def __init__(self):
    #     self.symbolMap = {}
    # def intToRoman(self, num):
    #     """
    #     :type num: int
    #     :rtype: str
    #     """
    #     result = ''
        
    # def intToRomanRecursion(self, num, output):
    #     num_copy = num
    #     remainder = 0
    #     while num_copy != 0:
    #         remainder = num_copy % 10
    #         num_copy //= 10
    #     if (remainder == 4 or remainder == 9):
    #     else:
            
            
            
        
# @lc code=end

