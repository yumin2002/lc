/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        
        return res;
    }
    void dfs (vector<int> & nums, vector<vector<int>> & res, int i, vector<int> curr) {
        if (i == nums.size()) {
            res.push_back(curr);
            return;
        }
        dfs
    }
};
// @lc code=end

