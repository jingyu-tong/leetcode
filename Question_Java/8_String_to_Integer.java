class Solution {
    public int myAtoi(String s) {
        if (s.isEmpty()) return 0;
        char[] chs = s.toCharArray();
        int sign = 1;
        int cur = 0;
        // 跳空格
        for (; cur < chs.length; ++cur) {
            if (chs[cur] != ' ') break;
        }
        if (cur < chs.length && (chs[cur] == '-' || chs[cur] == '+')) {
            sign = chs[cur] == '-' ? -1 : 1;
            ++cur;
        }

        int ans = 0;
        while (cur < chs.length) {
            if (chs[cur] > '9' || chs[cur] < '0') return ans * sign;
            int num = chs[cur] - '0';
            if (ans > Integer.MAX_VALUE / 10) return sign == -1 ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            if (ans == Integer.MAX_VALUE / 10) {
                if (sign == 1 && num >= 7) return Integer.MAX_VALUE;
                if (sign == -1 && num >= 8) return Integer.MIN_VALUE; 
            }
            ans = ans * 10 + num;
            ++cur;
        }
        return ans * sign;
    }
}