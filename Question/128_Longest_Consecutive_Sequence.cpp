class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mem; //num, 左边连续的个数
        int ans = 0;
        for(auto& num : nums) {
            if(mem.count(num) != 0) continue; // 跳过重复的
            auto iter_l = mem.find(num - 1);
            auto iter_r = mem.find(num + 1);

            int l = iter_l == mem.end() ? 0 : iter_l->second;
            int r = iter_r == mem.end() ? 0 : iter_r->second;

            int count = l + r + 1;
            ans = max(count, ans);
            mem[num] = count;
            //只更新两侧的，因为中间的会被跳掉
            mem[num - l] = count;
            mem[num + r] = count;
        }
        return ans;
    }
};
