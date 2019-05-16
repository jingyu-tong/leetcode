bool myCmp(int num1, int num2) {
    return to_string(num1) + to_string(num2) > to_string(num2) + to_string(num1);
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans;
        sort(nums.begin(), nums.end(), myCmp);
        for(auto num : nums)
            ans += to_string(num);
        return ans[0] == '0' ? "0" : ans;
    }
};