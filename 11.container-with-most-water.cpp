/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */
// Explanation:
// https://leetcode.com/problems/container-with-most-water/solutions/2363527/the-most-clear-explanation-of-the-greedy-approach/?q=greedy+explan&orderBy=most_relevant

    //smaller height defines the height of the container. 
    // Moving smaller border may lead to a bigger container
    // Moving greater border always leads to a smaller container

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxArea = 0;
        while (left < right) {
            maxArea = max(maxArea, (right-left) * min(height[left], height[right]));
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return maxArea;
    }
};
// @lc code=end

