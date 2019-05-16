/*
**hash T(n) = O(n) S(n) = O(n)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mem;
        int time = 0;
        for(const auto& num : nums) {
            ++mem[num];
            time = max(time, mem[num]);
        }

        for(const auto& i : mem) {
            if(i.second == time)
                return i.first;
        }
        return -1;
    }
};
/*
**摩尔算法，太巧了吧。。 T(n) = O(n) S(n) = O(1)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0, cnt = 0;
        for(const int &num : nums) {
            if(cnt == 0) {
                ans = num;
                ++cnt;
            } else {
                num == ans ? ++cnt : --cnt;
            }
        }
        return ans;
    }
};