//维护中间左侧一个最大堆 中间右侧一个最小堆
//同时需要维护长度 left == right or left = right + 1
class Solution {
public:
    void Insert(int num)
    {
        if(left.empty() || num <= left.top()) left.push(num);
        else right.push(num);
        
        if(left.size() == right.size() + 2) {right.push(left.top()); left.pop();}
        if(left.size() + 1 == right.size()) {left.push(right.top()); right.pop();}
    }

    double GetMedian()
    { 
        return right.size() == left.size() ? (left.top() + right.top()) / 2.0 : left.top();
    }
private:
    priority_queue<int, vector<int>, less<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;
};