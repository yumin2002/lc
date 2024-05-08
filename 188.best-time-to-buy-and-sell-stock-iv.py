#
# @lc app=leetcode id=188 lang=python
#
# [188] Best Time to Buy and Sell Stock IV
#

# @lc code=start
class Solution(object):
    # 05/07 first try
    def maxProfit(self, k, prices):
        # find every continous increase of prices
        length = len(prices)
        transactions = []
        start = -1
        end = -1
        for i in range(1, length):
            if prices[i] >= prices[i-1]:
                if start == -1:
                    start = i - 1
                    end = i
                else:
                    end += 1
            else:
                if start != -1:
                    transactions.append((start, end))
                    start = -1
                    
        if start != -1:
            transactions.append((start, end))
            
        print(transactions)
        
        # keep popping transactions until within k number of transaction
        while (len(transactions) > k):
            # calcluate minimum delete loss
            delete_index = 0
            delete_profit_loss = float('inf')
            for i in range(len(transactions)):
                curr_transaction = transactions[i]
                curr_profit_loss = prices[curr_transaction[1]] - prices[curr_transaction[0]]
                if curr_profit_loss < delete_profit_loss:
                    delete_index = i
                    delete_profit_loss = curr_profit_loss
            
            # calculate minimum merge loss
            merge_index = 1
            merge_profit_loss = float('inf')
            for i in range(1, len(transactions)):
                curr_transaction = transactions[i]
                prev_transaction = transactions[i-1]
                curr_profit_loss = prices[prev_transaction[1]] - prices[curr_transaction[0]]
                if curr_profit_loss < merge_profit_loss:
                    merge_index = i
                    merge_profit_loss = curr_profit_loss
            
            print(delete_index)
            print(merge_index)
            if delete_profit_loss <= merge_profit_loss:
                transactions.pop(delete_index)
            else:
                transactions[merge_index-1] = (transactions[merge_index-1][0], transactions[merge_index][1])
                transactions.pop(merge_index)
                
                
                
                
        print(transactions)
        return sum((prices[transaction[1]] - prices[transaction[0]]) for transaction in transactions)
        
    
    
    
    # # TODO: retry
    # # 1. first, find out all the increasing subsequence
    # # 2. delete or merge a transacton will reduce the total number of transaction by 1
    # # 3. reduce the number of transactions by comparing delete and merge loss until it is <= k (satisfy requirement)
    # #   explanation: everytime we reduce the number of transactions, we compute the merge loss and delete loss.
    # def maxProfit(self, k, prices):
    #     n = len(prices)

    #     # solve special cases
    #     if not prices or k == 0:
    #         return 0

    #     # find all consecutively increasing subsequence, record their start and end
    #     transactions = []
    #     start = 0
    #     end = 0
    #     for i in range(1, n):
    #         if prices[i] >= prices[i-1]:
    #             end = i
    #         else:
    #             if end > start:
    #                 transactions.append([start, end])
    #             start = i
    #     if end > start:
    #         transactions.append([start, end])

    #     while len(transactions) > k:
    #         # check delete loss: lose the minimum transaction
    #         delete_index = 0
    #         min_delete_loss = float('inf')
    #         for i in range(len(transactions)):
    #             t = transactions[i]
    #             profit_loss = prices[t[1]] - prices[t[0]]
    #             if profit_loss < min_delete_loss:
    #                 min_delete_loss = profit_loss
    #                 delete_index = i

    #         # check merge loss: lose the minimum difference(the decreasing portion) in between of the two transactions
    #         # in this case, always merge to the previous transaction (should be able to cover all n-1 merging possibilities)
    #         merge_index = 0
    #         min_merge_loss = float('inf')
    #         for i in range(1, len(transactions)):
    #             t1 = transactions[i-1]
    #             t2 = transactions[i]
    #             profit_loss = prices[t1[1]] - prices[t2[0]]
    #             if profit_loss < min_merge_loss:
    #                 min_merge_loss = profit_loss
    #                 merge_index = i

    #         # delete or merge
    #         if min_delete_loss <= min_merge_loss:
    #             transactions.pop(delete_index)
    #         else:
    #             transactions[merge_index - 1][1] = transactions[merge_index][1]
    #             transactions.pop(merge_index)

    #     # sum up all profits
    #     return sum(prices[j]-prices[i] for i, j in transactions)
    
    # def maxProfit(self, k, prices):
    #     """
    #     :type k: int
    #     :type prices: List[int]
    #     :rtype: int
    #     """
    #     length = len(prices)
    #     increase_magnitude = []
    #     curr_profit = 0
    #     min_price_so_far = prices[0]
    #     max_profit_so_far = 0
    #     for i in range(1, length):
    #         max_profit_so_far = max(max_profit_so_far, prices[i] - min_price_so_far)
    #         min_price_so_far = min(min_price_so_far, prices[i])
    #         if prices[i] < prices[i-1]:
    #             increase_magnitude.append((curr_profit, max_profit_so_far))
    #             print(curr_profit)
    #             curr_profit = 0
    #         else:
    #             curr_profit += prices[i] - prices[i-1]
    #             if i == length - 1:
    #                 increase_magnitude.append((curr_profit, max_profit_so_far))
    #                 print(curr_profit)

    #     increase_magnitude.sort(reverse=True)
    #     max_profit = 0
    #     if k >= len(increase_magnitude):
    #         for i in range(0, len(increase_magnitude)):
    #             max_profit += increase_magnitude[i][0]
    #     else:
    #         for i in range(0, k):
    #             if i == k - 1:
    #                 max_profit += increase_magnitude[i][1]
    #             else:
    #                 max_profit += increase_magnitude[i][0]
    #      return max_profit
            
        
        
# @lc code=end

