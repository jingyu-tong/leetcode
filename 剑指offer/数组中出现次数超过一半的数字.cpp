//统计次数 + 验证有效性
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty()) return 0;
        
        const int n = numbers.size();
        int count = 1;
        int ans = numbers[0];
        for(int i = 1; i < n; ++i) {
            if(numbers[i] == ans) ++ count;
            else {
                if(count == 0) {
                    ans = numbers[i];
                    count = 1;
                } else {
                    --count;
                }
            }
        }
        
        //valid?
        count = 0;
        for(int i = 0; i < n; ++i) {
            if(numbers[i] == ans) ++count;
            if(count > (n >> 1)) return ans;
        }
        return 0;
    }
};