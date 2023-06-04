/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        return longestStr(s, maxLen, 0, s.length()-1);
    }
    string longestStr(string s, int & maxLen, int begin, int end) {
        if (s.length() == 0) return "";
        if (s[0] == s.[s.length()-1]) 
    }
};
// @lc code=end

