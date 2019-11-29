class Solution {
public:
    int jumpFloorII(int number) {
        if(number <= 2) return number;
        
        int ans = 2;
        for(int i = 3; i <= number; ++i) {
            ans += ans;
        }
        return ans;
    }
};