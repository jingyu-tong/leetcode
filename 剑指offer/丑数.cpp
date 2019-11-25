class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index < 7) return index;
        
        vector<int> ans(index);
        ans[0] = 1;
        int ind2 = 0;
        int ind3 = 0;
        int ind5 = 0;
        for(int i = 1; i < index; ++i) {
            ans[i] = min(ans[ind2] * 2, min(ans[ind3] * 3, ans[ind5] * 5));
            if(ans[i] == ans[ind2] * 2) ++ind2;
            if(ans[i] == ans[ind3] * 3) ++ind3;
            if(ans[i] == ans[ind5] * 5) ++ind5;
        }
        return ans.back();
    }
};