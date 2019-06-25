/*
**两个堆各维护一半左右的元素
*/
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(l_.empty() || num <= l_.top()) {
            l_.push(num);
        } else {
            r_.push(num);
        }
        
        //banlance l and r
        if(l_.size() < r_.size()) {
            l_.push(r_.top());
            r_.pop();
        } else if(l_.size() - r_.size() == 2) {
            r_.push(l_.top());
            l_.pop();
        }
    }
    
    double findMedian() {
        if(l_.size() > r_.size()) {
            return static_cast<double>(l_.top());
        } else {
            return static_cast<double>( (l_.top() + r_.top()) / 2.0);
        }
    }
private:
    priority_queue<int, vector<int>, less<int>> l_;     // max heap
    priority_queue<int, vector<int>, greater<int>> r_;     // min heap    
};
/*
**平衡二叉树
*/
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder(): l_(m_.cend()), r_(m_.cend()) {
        
    }
    
    // O(logn)
    void addNum(int num) {
        if (m_.empty()) {
            l_ = r_ = m_.insert(num);
            return;
        }
        
        m_.insert(num);
        const size_t n = m_.size();    
        
        if (n & 1) {
            // odd number
            if (num >= *r_) {         
                l_ = r_;
            } else {
                // num < *r_, l_ could be invalidated
                l_ = --r_;
            }
        } else {
            if (num >= *r_)
                ++r_;
            else
                --l_;
        }
    }
    
    double findMedian() {
         return static_cast<double>( (*l_ + *r_) / 2.0);
    }
private:
    multiset<int> m_;
    multiset<int>::const_iterator l_;  // current left median
    multiset<int>::const_iterator r_;  // current right median
};

