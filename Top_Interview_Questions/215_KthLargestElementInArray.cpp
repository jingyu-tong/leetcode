class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1)
                return nums[pos];
            else if (pos > k - 1)
                right = pos - 1;
            else
                left = pos + 1;
        }
    }

private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && pivot < nums[r]) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) ++l;
            if (nums[r] <= pivot) --r;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};

// 小顶堆
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (k <= 0 || k > nums.size()) return -1;

        priority_queue<int, vector<int>, greater<int>> q;  // 小顶堆
        for (int i = 0; i < nums.size(); ++i) {
            if (q.size() < k) {
                q.push(nums[i]);
                continue;
            }
            if (nums[i] <= q.top()) continue;
            q.pop();
            q.push(nums[i]);
        }
        return q.top();
    }
};