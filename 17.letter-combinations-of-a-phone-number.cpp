/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// recursive

// @lc code=start
// class Solution {
// public:
//     vector<string> letterCombinations(string digits) {
//         if (digits == "") {
//             vector<string> res;
//             return res;
//         }
//         unordered_map<char, vector<char>> myMap;
//         for (int i = 2; i < 7; i ++) {
//             char start = 'a'+(i-2)*3;
//             char second = start + 1;
//             char third = start + 2;
//             vector<char> vec{start, second, third};
//             myMap['0'+i] = vec;
//         }
//         myMap['7'] = {'p','q','r','s'};
//         myMap['8'] = {'t', 'u', 'v'};
//         myMap['9'] = {'w','x','y','z'};
//         vector<string> res;
//         dfs(digits, 0, "", res,myMap);
//         return res;
//     }
//     void dfs(string digits, int i, string curr, vector<string> & res, 
//         unordered_map<char,vector<char>> & myMap) {
//         if (i == digits.length()) res.push_back(curr);
//         // iterate through vector key of map
//         for (int j = 0; j < myMap[digits[i]].size(); j++) {
//             dfs(digits, i+1, curr+myMap[digits[i]][j],res,myMap);
//         }
//     }
// };

// iterative
class Solution {
public:
    const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
		vector<string> result;
        result.push_back("");
        
        // for each digit
        for(auto digit: digits) {
            vector<string> tmp;
            // for each char corresponsing to the digit
            for(auto candidate: pad[digit - '0']) {
                // iterate through result of last digit
                for(auto s: result) {
                    // concatonate the result to the string
                    tmp.push_back(s + candidate);
                }
            }
            // tmp become the new result
            result.swap(tmp);
        }
        return result;
    }
};
// @lc code=end


