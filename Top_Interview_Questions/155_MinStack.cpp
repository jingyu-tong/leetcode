class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        s1_.push(x);
        if (s2_.empty() || x <= s2_.top()) s2_.push(x);
    }

    void pop() {
        if (s1_.top() == s2_.top()) s2_.pop();
        s1_.pop();
    }

    int top() { return s1_.top(); }

    int getMin() { return s2_.top(); }

private:
    stack<int> s1_;  // 全部元素
    stack<int> s2_;  // 最小元素
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */