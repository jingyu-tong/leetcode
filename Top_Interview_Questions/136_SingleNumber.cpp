/*
**hash space complexity O(n)
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mem;
        for(const auto &num : nums) {
            ++mem[num];
        }
        
        for(const auto& i : mem) {
            if(i.second == 1)
                return i.first;
        }
        return -1;
    }
};
/*
**异或 。。。
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(const auto &num : nums) {
            ans ^= num;
        }
        return ans;
    }
};