#include <unordered_map>
#include <vector>
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mem;  // value to index
        for (int i = 0; i < nums.size(); ++i) {
            if (mem.count(target - nums[i]) != 0)
                return {i, mem[target - nums[i]]};
            mem[nums[i]] = i;
        }
        return {-1, -1};
    }
};

TEST(test, case0) {
    vector<int> input({2,7,11,15});
    int target = 9;
    vector<int> output1{1, 0};
    vector<int> output2{0, 1};
    Solution s;
    EXPECT_TRUE(output1 == s.twoSum(input, target) || output2 == s.twoSum(input, target));
}


