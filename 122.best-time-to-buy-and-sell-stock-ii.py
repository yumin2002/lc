#
# @lc app=leetcode id=122 lang=python
#
# [122] Best Time to Buy and Sell Stock II
#

# @lc code=start
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        profit = 0
        for i in range(1,len(prices)):
            if prices[i] > prices[i-1]:
                profit += prices[i] - prices[i-1]
        return profit

        # analysis:
        #  time O(n)
        #  space O(1)
        # 
        # Approach: Greedy
        # For each interval of one day, we make a decision of whether to 
        # buy at the earlier day and sell at a later day. We will perform the 
        # transaction as long as the profit is positive.
        # 
        # interview script:
        #  1. The method is designed to capitalize on every increment between consecutive days
        #  2. one should buy stocks at a lower price one day and sell them at a higher price the next to maximize overall profit
        #  3. This approach is optimal because you're essentially capturing the profit of every upward trend
        #  4. it takes advantage of every possible profitable transaction without missing any opportunities presented by the array of prices
# @lc code=end

