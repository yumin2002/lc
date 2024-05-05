/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
private:
    std::stack<int> stacc;
    std::stack<int> q;
public:
    MyQueue() {
    }
    
    void push(int x) {
        stacc.push(x);
    }
    
    int pop() {
        if (!q.empty()) {
            int temp = q.top();
            q.pop();
            return temp;
        }
        while (!stacc.empty()) {
            q.push(stacc.top());
            stacc.pop();
        }
        int temp = q.top();
        q.pop();
        return temp;
    }
    
    int peek() {
        if (!q.empty()) {
            return q.top();
        }
        while (!stacc.empty()) {
            q.push(stacc.top());
            stacc.pop();
        }
        return q.top();
    }
    
    bool empty() {
        return stacc.empty() && q.empty();
    }
};


/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end