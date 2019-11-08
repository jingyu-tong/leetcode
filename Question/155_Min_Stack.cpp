class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min_ = INT_MAX;
    }

    void push(int x) {
        nums_.push_back(x);
        min_ = min(min_, x);
    }

    void pop() {
        nums_.pop_back();
        if(nums_.size() >= 1) min_ = *min_element(nums_.begin(), nums_.end());
        else min_ = INT_MAX;
    }

    int top() {
        if(nums_.empty()) return -1;
        else return nums_.back();
    }

    int getMin() {
        if(nums_.empty()) return -1;
        return min_;
    }
private:
    int min_;
    vector<int> nums_;
};
