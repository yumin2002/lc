/*
 * @lc app=leetcode id=759 lang=cpp
 *
 * [757] Set Intersection Size At Least Two
 */
bool comp(vector<int> vec1, vector<int> vec2) {
    if(vec1[0] == vec2[0]) return vec1[1] < vec2[1];
    return vec1[0] < vec2[0];
}
// @lc code=start
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        unordered_set<int> set;
        int leftoff = intervals[0][0];
        pair<int,int> best = {0, 0};
        pair<int,int> best = {0, 0};
        for (int i = 0; i < intervals.length(); i++) {
            while (leftoff <= intervals[i][1]) {
                
            }
        }
    }
};
// @lc code=end

