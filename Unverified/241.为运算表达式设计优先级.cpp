/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution {
private:
    vector<int> divideAndconquer(string expression, int start, int end) {
        vector<int> re;
        bool divide = false;
        for (size_t i(start); i <= end; ++i) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                divide = true;
                merge(divideAndconquer(expression, start, i-1), divideAndconquer(expression, i+1, end), expression[i], re);
            }
        }
        if (!divide && start <= end) {
            int tmp = 0;
            for (int i(start); i <= end; ++i) {
                tmp *= 10;
                tmp += (expression[i] - '0');
            } 
            re.emplace_back(tmp);
        }
        return re;
    }

    void merge(vector<int> a, vector<int> b, char ex, vector<int> &re) {
        for (auto i:a) {
            for (auto j:b) re.emplace_back(compute(i, j, ex));
        } 
    }

   int compute(int i, int j, char ex) {
       if (ex == '+') return i+j;
       if (ex == '-') return i-j;
       return i*j;
   }
public:
    vector<int> diffWaysToCompute(string expression) {
        return divideAndconquer(expression, 0, expression.size()-1);
    }
};
// @lc code=end

