#
# @lc app=leetcode id=155 lang=python3
#
# [155] Min Stack
#

# @lc code=start

# maintain a stack recording the minimum element at different level of index
class MinStack:

    def __init__(self):
        self.s = []
        self.min = []

    def push(self, val: int) -> None:
        self.s.append(val)
        if (len(self.min) == 0):
            self.min.append(val)
            return
        currMin = self.min[-1]
        if val < currMin:
            self.min.append(val)
        else:
            self.min.append(currMin)

    def pop(self) -> None:
        self.s.pop()
        self.min.pop()
        
        

    def top(self) -> int:
        return self.s[-1]

    def getMin(self) -> int:
        return self.min[-1]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
# @lc code=end

