class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        if(num.size() < size || size < 1) return {};
        
        vector<int> ans;
        deque<int> q; //单调递增栈
        for(int i = 0; i < size; ++i) {
            while(!q.empty() && num[i] >= num[q.back()]) //弹出更小的
                q.pop_back();
            q.push_back(i);
        }
        
        for(int i = size; i < num.size(); ++i) {
            ans.push_back(num[q.front()]);
            while(!q.empty() && num[i] >= num[q.back()]) //弹出更小的
                q.pop_back();
            if(!q.empty() && q.front() <= i - size) //已经失效
                q.pop_front(); 
            q.push_back(i);
        }
        ans.push_back(num[q.front()]);
        return ans;
    }
};