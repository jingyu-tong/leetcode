//快排思路，O(n)
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.size() < k) return {};
        if(input.size() == k) return input;
        if(k <= 0) return {};
        
        int begin = 0;
        int end = input.size() - 1;
        int index = partition(input, begin, end);
        while(index != k - 1) {
            if(index > k - 1) { //left part
                end = index - 1;
                index = partition(input, begin, end);
            } else {
                begin = index + 1;
                index = partition(input, begin, end);
            }
        }
        vector<int> ans(input.begin(), input.begin() + k);
        return ans;
    }
private:
    int partition(vector<int>& nums, int left, int right) {
        swap(nums[left], nums[left + rand() % (right - left + 1)]); //随机取
        int pivot = nums[left];
        while(left < right) {
            while( (left < right) && (pivot <= nums[right])) //找到第一个比pivot小的
                --right;
            nums[left] = nums[right];
            while( (left < right) && (nums[left] <= pivot)) //找到第一个大的，换到右边
                ++left;
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }
};

//构造一个k个element的最大堆，复杂度O(nlogk)
//虽然平均复杂度不如快排方案，但是这种方式适合海量数据
//可以不断的从海量数据中读入元素，内存只需要维护大小为k的最大堆即可
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.size() < k) return {};
        if(input.size() == k) return input;
        if(k <= 0) return {};
        
        priority_queue<int> q(input.begin(), input.begin() + k);
        
        for(int i = k; i < input.size(); ++i) {
            if(q.top() <= input[i]) continue;
            
            q.pop();
            q.push(input[i]);
        }
        
        vector<int> ans(q.size());
        for(int i = 0; i < ans.size(); ++i) {
            ans[i] = q.top();
            q.pop();
        }
        return ans;
    }
};