class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size() == 0) return {1};

        vector<int> ans;
        int flag = 1;
        for(int i = digits.size() - 1; i >= 0; --i) {
            int num = digits[i] + flag;
            ans.push_back(num % 10);
            flag = num / 10;
        }
        if(flag == 1) ans.push_back(flag);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
