//这题感觉还蛮有意思，首先肯定需要一个额外的数据结构来表示
//因为最小的元素随时可以出栈，其实需要一个类似排过序的数据结构
//最开始想的是hash储存元素和次数+变量min，但是这种方法在更新min的时候要遍历，也就是O(n)
//翻看书上的例子发现：
//这里可以利用堆栈的性质，只能从栈顶出，那么我们也用一个栈保存对应位置的答案就可
class Solution {
public:
    void push(int value) {
        s_.push(value);
        if(min_.empty()) min_.push(value);
        else min_.push(min_.top() > value ? value : min_.top());
    }
    void pop() {
        if(!s_.empty()) {
            s_.pop();
            min_.pop();
        }
    }
    int top() {
        if(s_.empty()) return -1;
        
        return s_.top();
    }
    int min() {
        if(min_.empty()) return -1;
        
        return min_.top();
    }
private:
    stack<int> s_;
    stack<int> min_;//辅助
};