/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        backtrack(nums, 0, count, 0, target);
        return count;
    }
    void backtrack(vector<int> & nums, int i, int & count, int currRes, int target) {
        if (i == nums.size() && currRes == target) {
            count++;
            return;
        }
        else if (i == nums.size()) {
            return;
        }
        backtrack(nums,i+1,count,currRes + nums[i],target);
        backtrack(nums,i+1,count,currRes - nums[i],target);

    }
};
// @lc code=end
// only at position i we increment


// Time complexity: O(2^n). Size of recursion tree will be 2^n. n refers to the size of nums array.

// Space complexity: O(n). The depth of the recursion tree can go up to n.
