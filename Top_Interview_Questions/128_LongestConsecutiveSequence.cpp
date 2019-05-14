class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mem;
        int ans = 0;
        for(auto num : nums) {
            if(mem.count(num)) continue;
            
            auto it_l = mem.find(num - 1);
            auto it_r = mem.find(num + 1);
            
            int l = it_l != mem.end() ? it_l->second : 0;
            int r = it_r != mem.end() ? it_r->second : 0;
            int t = r + l + 1;
            
            mem[num] = mem[num - l] = mem[num + r] = t;
            ans = max(ans, t);
        }
        return ans;
    }
};