class Solution {
public:
    //摩尔投票
    //数组中有超过半数的元素话，选择两个不同的元素删掉，最后剩的一个或几个相同的，一定是那个元素
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int ans;
        for(auto& num : nums) {
            if(count == 0) {
                ans = num;
                ++count;
            } else {
                num == ans ? ++count : --count;
            }
        }
        return ans;
    }
};
