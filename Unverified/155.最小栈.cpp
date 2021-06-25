/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
private:
    std::stack<long long> diff;
    long long _min;
public:
    /** initialize your data structure here. */
    MinStack() {
        _min = INT_MAX;
    }
    
    void push(int val) {
        if (diff.empty()) {
            diff.push(0);
            _min = val;
        } else {
            long long temp = val - _min;
            diff.push(temp);
            if (temp < 0) {
                _min = val;
                cout << _min;
            }
        }
    }
    
    void pop() {
        if (!diff.empty()) {
            if (diff.top() < 0) _min = _min - diff.top();
            diff.pop();
        }
    }
    
    int top() {
        if (!diff.empty()) {
            long long top;
            long long temp = diff.top();
            if (temp < 0) top = _min;
            else top = _min + temp;
            return top;
        }
        return -1;
    }
    
    int getMin() {
        if (! diff.empty()) return _min;
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

