// avoid modifying a set while iterating
/*
 * @lc app=leetcode id=839 lang=cpp
 *
 * [820] Short Encoding of Words
 */

// @lc code=start
// bool comp(string & a, string & b) {
//     return a.length() > b.length();
// }
class Solution {
public:
    // check if the current word is the postfix of words[i] or if words[i] is the postfix of the current word
    // keep the word that contains
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        string res = "";
        for (string curr : words) {
            int index = res.find(curr+"#");
            if (index == -1) res += curr+"#";
        }
        return res.length();
    }
};
// @lc code=end

