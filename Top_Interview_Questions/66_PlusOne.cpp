/*
**新建了一个向量，空间复杂度不好，但感觉该digits不太好
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans(digits);
        int flag = 0;
        ans.back() = ans.back() + 1;
        for(int i = ans.size() - 1; i >= 0; --i) {
            int temp = ans[i] +flag;
            ans[i] = temp % 10;
            flag = temp / 10;
        }
        if(flag == 1)
            ans.insert(ans.begin(), 1);
        return ans;
    }
};