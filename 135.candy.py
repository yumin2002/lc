#
# @lc app=leetcode id=135 lang=python
#
# [135] Candy
#

# @lc code=start
class Solution(object):
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        # TODO: Need retry
        # Greedy and DP
        # whenever we increase the candies at index i for a certain candiate, there are 3 things we need to worry about
        # violation case 1: rating[i-1] > rating[i] but candies[i-1] < candies[i]
        # violation case 2: rating[i] < rating[i+1] but candies[i] > candies[i+1]
        # the basic implemetation will use two array
        # 1. canidies_left: the relationship between any i-1 and i cannot be violated
        # 2. candies_right: the relationship between any i and i+1 cannot be violated
        # After we generate these two memo, for each index i, the minimum candies assign should be:
        # max(candies_left[i], candies_right[i])
        # by optimizing the space complexty we can get O(1) for the following solution
        candies = [1] * len(ratings)
        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i-1]:
                candies[i] = candies[i-1] + 1
        for i in range(len(ratings) - 2, -1, -1):
            if ratings[i] > ratings[i+1] :
                candies[i] = max(candies[i], candies[i+1] + 1)
        return sum(candies)            
        
# @lc code=end
