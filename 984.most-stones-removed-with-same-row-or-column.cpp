/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [984] String Without AAA or BBB
 */

// @lc code=start
class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string res = "";
        int i = 0;
        while (a > 0 || b > 0) {
            if (res.length() >= 2 && res[i-1] == res[i-2]) {
                if (res[i-1] == 'a'){
                    res += "b";
                    b--;
                }
                else {
                    res += "a";
                    a--;
                }
            }
            else{
                if (a > b){
                    res+="a";
                    a--;
                }
                else{
                    res+="b";
                    b--;
                }
            }
            i++;
        }
        return res;
    }
};
// @lc code=end

// write the most common letter remaining unless the remaining ones are