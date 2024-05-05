/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            // front parentheses
            if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
                st.push(s[i]);
            }
            // closing parentheses
            else {
                if (st.empty()) return false;
                if (s[i] == '}' && st.top() == '{') {
                    st.pop();
                } else if (s[i] == ')' && st.top() == '(') {
                    st.pop();
                } else if (s[i] == ']' && st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        if (!st.empty()) {
            return false;
        }
        return true;
    }
};
// @lc code=end

