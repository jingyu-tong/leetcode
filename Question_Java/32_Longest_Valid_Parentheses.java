class Solution {
    public int longestValidParentheses(String s) {
        Deque<Integer> st = new ArrayDeque<>();
        int left = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s.charAt(i);
            if (ch == '(') {
                st.push(i);
                continue;
            }
            if (st.size() == 0) {
                left = i + 1;
            } else {
                st.pop();
                if (st.size() == 0) ans = Math.max(ans, i - left + 1);
                else ans = Math.max(ans, i - st.peek());
            }
        }
        return ans;
    }
}