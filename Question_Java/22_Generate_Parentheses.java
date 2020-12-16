class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        dfs(n, n, new StringBuilder(), ans);
        return ans;
    }
    void dfs(int left, int right, StringBuilder cur, List<String> ans) {
        if (left < 0 || right < 0) return;
        if (left == 0 && right == 0) {
            ans.add(cur.toString());
            return;
        }
        if (right < left) return;

        cur.append('(');
        dfs(left - 1, right, cur, ans);
        cur.deleteCharAt(cur.length() - 1);
        cur.append(')');
        dfs(left, right - 1, cur, ans);
        cur.deleteCharAt(cur.length() - 1);
    }
}