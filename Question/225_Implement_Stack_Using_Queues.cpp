class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
        for(int i = q1.size(); i > 1; --i) {
            q2.push(q1.front());
            q1.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp = top();
        q1.pop();
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        if(q1.empty()) {
            for(int i = q2.size(); i > 1; --i) {
                q2.push(q2.front());
                q2.pop();
            }
            q1.push(q2.front()); q2.pop();
        }
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
private:
    queue<int> q1; //栈顶
    queue<int> q2; //维护所有元素，每次至多取一个到q1
};
