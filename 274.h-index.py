#
# @lc app=leetcode id=274 lang=python
#
# [274] H-Index
#

# @lc code=start
class Solution(object):
    # TODO: O(n) solution 
    # soooo confused
    
    
    # O(nlogn) using sorting
    # sort the citations in ascending order
    # iterate through the citations 
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        citations.sort()
        # print(citations)
        k = -1
        for i in range(0, len(citations)):
            paper_qualified = len(citations) - i
            minimum_citation = citations[i]
            k = max(k, min(paper_qualified, minimum_citation))
        return k
            
        
# @lc code=end

