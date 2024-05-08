#
# @lc app=leetcode id=380 lang=python
#
# [380] Insert Delete GetRandom O(1)
#

# @lc code=start
# The data structure maintains two components:
# 1. A list that holds all the inserted elements, enabling O(1) access by index.
# 2. A hash map that maps each element to its index in the list, allowing for O(1) search time.

# The key challenge is to support constant time operations for insertion, deletion, and random access.
# Random access is straightforward with a list by generating a random index.
# Insertion at the end of a list is O(1), and using a hash map allows us to insert and check existence in O(1) time.

# For deletion, to maintain continuous elements in the list and still achieve O(1) complexity:
# - Identify the element's index using the hash map.
# - Swap the element with the last element in the list (if it's not already the last one).
# - Update the swapped element's index in the hash map.
# - Remove the last element from the list.
# - Delete the element from the hash map.
class RandomizedSet(object):

    def __init__(self):
        # element - index in array
        self.myMap = {}
        # element container
        self.myList = []
        

    def insert(self, val):
        """
        :type val: int
        :rtype: bool
        """
        if val in self.myMap:
            return False
        else: 
            self.myMap[val] = len(self.myList)
            self.myList.append(val)
            return True
        

    def remove(self, val):
        """
        :type val: int
        :rtype: bool
        """
        if val not in self.myMap:
            return False
        else:
            index = self.myMap[val]
            replaced_element = self.myList[index]
            last_element = self.myList[-1]            
            self.myList[index] = last_element
            self.myList.pop()
            
            self.myMap[last_element] = index
            del self.myMap[replaced_element]
            return True

        

    def getRandom(self):
        """
        :rtype: int
        """
        return choice(self.myList)
        
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
# @lc code=end

