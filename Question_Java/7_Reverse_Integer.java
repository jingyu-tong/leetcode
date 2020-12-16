class Solution {
    public int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            if (Math.abs(ans) > Integer.MAX_VALUE / 10)
                return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
}
