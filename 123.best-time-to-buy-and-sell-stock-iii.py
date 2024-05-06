#
# @lc app=leetcode id=123 lang=python
#
# [123] Best Time to Buy and Sell Stock III
#

# @lc code=start
class Solution(object):
    # DP solution:
    # 1. construct 2 DP arrays:
    #   left_profits: maximum profit for subarray from 0 to any index
    #   right_profits: maxmum profit for subarray from any index to length-1
    # 2. for every different partition, compute a maximum total profit
    #   find out the global maximum
    def maxProfit(self, prices):
        left_min = prices[0]
        right_max = prices[-1]

        length = len(prices)
        left_profits = [0] * length
        # pad the right DP array with an additional zero for convenience.
        right_profits = [0] * (length + 1)

        # construct the bidirectional DP array
        for l in range(1, length):
            left_profits[l] = max(left_profits[l - 1], prices[l] - left_min)
            left_min = min(left_min, prices[l])

            r = length - 1 - l
            right_profits[r] = max(right_profits[r + 1], right_max - prices[r])
            right_max = max(right_max, prices[r])

        max_profit = 0
        for i in range(0, length):
            max_profit = max(max_profit, left_profits[i] + right_profits[i + 1])

        return max_profit
    
    
    
    # #1: bruteforce solution timelimit exceeded 
    # time complexity: O(n)
    # def maxProfit(self, prices):
    #     """
    #     :type prices: List[int]
    #     :rtype: int
    #     """
    #     # given that the first transaction happens by i, and the second transaction happens after i
    #     # compute the local maximum for two different subarray
    #     # the addition is the maximum profit
    #     # there are len(prices) ways to partition the array
    #     globalMax = 0
    #     for i in range(len(prices)):
    #         transaction1Profit = self.maxProfitSingleTransaction(0,i+1,prices)
    #         transaction2Profit = self.maxProfitSingleTransaction(i,len(prices),prices)
    #         # print(transaction1Profit)
    #         # print(transaction2Profit)
    #         localMax = transaction1Profit + transaction2Profit
    #         globalMax = localMax if globalMax < localMax else globalMax
    #     return globalMax
        
    
    # def maxProfitSingleTransaction(self, start, end, prices):
    #     currMax = 0
    #     buy_index = start
    #     for i in range(start, end):
    #         local = prices[i] - prices[buy_index]
    #         currMax = local if local > currMax else currMax
    #         buy_index = i if prices[buy_index] > prices[i] else buy_index
    #     return currMax
        
# @lc code=end

