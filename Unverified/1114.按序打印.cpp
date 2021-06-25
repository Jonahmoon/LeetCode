/*
 * @lc app=leetcode.cn id=1114 lang=cpp
 *
 * [1114] 按序打印
 */

// @lc code=start
class Foo {
private:
    mutex s;
    mutex t;
public:
    Foo() {
        s.lock();
        t.lock();
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        s.unlock();
    }

    void second(function<void()> printSecond) {
        // printFirst() outputs "first". Do not change or remove this line.
        s.lock();
        printSecond();
        s.unlock();
        t.unlock();
    }

    void third(function<void()> printThird) {
        // printThird() outputs "third". Do not change or remove this line.
        t.lock();
        printThird();
        t.unlock();
    }
};
// @lc code=end
