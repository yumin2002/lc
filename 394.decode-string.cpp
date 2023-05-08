/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<string> myStack;
        for (int i = 0; i < s.size(); i++) {
            cout << s[i] << endl;
            if (s[i] >= '0' && s[i] <='9') {
                string currInt = "";
                while (i < s.size() && s[i] && s[i] >= '0' && s[i] <='9') {
                    currInt += s[i];
                    i++;
                }
                i--;
                cout << currInt << endl;
                myStack.push(currInt);
            }
            else if (s[i] == ']') {
                string currRes = "";
                string currString = "";
                while (myStack.top() != "[") {
                    currString += myStack.top();
                    myStack.pop();
                }
                myStack.pop();
                int count = stoi(myStack.top());
                myStack.pop();
                for (int j = 0; j < count; j++) {
                    currRes += currString;
                }
                myStack.push(currRes);
            }
            else {
                cout << s[i] << endl;
                string myS = "";
                myS += s[i];
                myStack.push(myS);
            }
        }
        while (!myStack.empty()){
            res+=myStack.top();
            myStack.pop();
        }
        string res2 = "";
        for (int i = res.length() - 1 ; i >= 0; i--) {
            res2+= res[i];
        }
        return res2;
    }
};
// @lc code=end

