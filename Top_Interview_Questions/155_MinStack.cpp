/*
**最一般的版本，每次都要求最小值 196ms
*/
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        ele_.push_back(x);
    }
    
    void pop() {
        ele_.pop_back();
        
    }
    
    int top() {
        return ele_.back();
    }
    
    int getMin() {
        return *min_element(ele_.begin(), ele_.end());
    }
private:
    int num_;
    vector<int> ele_;
    
};
/*
**可以在出栈入栈时更新最小值
*/
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min_ = INT_MAX;
    }
    
    void push(int x) {
        ele_.push_back(x);
        min_ = min(x, min_);
    }
    
    void pop() {
        if(ele_.size() > 1)
            min_ = *min_element(ele_.begin(), ele_.end() - 1);
        else 
            min_ = INT_MAX;
        ele_.pop_back();
        
    }
    
    int top() {
        return ele_.back();
    }
    
    int getMin() {
        return min_;
    }
private:
    int min_;
    int num_;
    vector<int> ele_;
    
};
