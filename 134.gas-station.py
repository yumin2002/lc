#
# @lc app=leetcode id=134 lang=python
#
# [134] Gas Station
#

# @lc code=start
class Solution(object):
    # TODO: need to retry and read the analysis
    # this problem can be separate into 2 questions:
    # 1. how to detect that the car is unable to complete the circular path?
    # 2. if possible to complete, where should it start?
    
    # 1: if and only if the sum of the cost is greater than the sum of gas, the car cannot complete the route
    #  i.e. sum(cost) > sum(gas)
    # 2:
    # at every index i, gas gained is gas[i] - cost[i]
    # the idea is :
    # traverse the array to partition the array into segments where the car cannot complete.
    # At the end of the array, there might be 2 situations:
    # 1. at the last index, the car reach a station where it cannot go further because of negative gain. There is no gas remaining to complete the ride(since it is circular).
    # 2. at the last index, the car is able to connect back to the begining of the array because of positive or 0 net gain. If there is a route, it should starts from the begining of this segment.
    
    # key point: (it is important to find the invariants for greedy algorithm questions)
    # 1. if the car starts from index i and failed to move to j, then the car will not be able to move to j from any point between i and j
    #  check why: https://leetcode.cn/problems/gas-station/solutions/488357/jia-you-zhan-by-leetcode-solution/
    
    # O(n) but less optimized algorithm, easy to understand:
    # https://leetcode.cn/problems/gas-station/solutions/25644/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--30/
    def canCompleteCircuit(self, gas, cost):
        total_gas = 0
        curr_gas = 0
        start = 0
        for i in range(len(cost)):
            gas_gain = gas[i] - cost[i]
            curr_gas = curr_gas + gas_gain
            total_gas += gas_gain
            if curr_gas < 0:
                start = i+1
                curr_gas = 0
        return start if total_gas >= 0 else -1
    
    # def canCompleteCircuit(self, gas, cost):
    #     """
    #     :type gas: List[int]
    #     :type cost: List[int]
    #     :rtype: int
    #     """
    #     total_cost = sum(cost)
    #     total_gas = sum(gas)
    #     if total_gas < total_cost:
    #         return -1
        
    #     curr_gas = 0
    #     start = 0
    #     for i in range(len(cost)):
    #         curr_gas = curr_gas + gas[i] - cost[i]
    #         if curr_gas < 0:
    #             start = i+1
    #             curr_gas = 0
    #     return start
                
        
# @lc code=end

