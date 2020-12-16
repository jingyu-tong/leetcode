class Solution {
    public List<String> letterCombinations(String digits) {
        if (digits.isEmpty())
            return new ArrayList<String>();
        String[] dict = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        char[] chs = digits.toCharArray();
        List<String> ans = new ArrayList<>();
        dfs(chs, dict, 0, new StringBuilder(), ans);
        return ans;
    }

    void dfs(char[] chs, String[] dict, int level, StringBuilder cur, List<String> ans) {
        if (level == chs.length) {
            ans.add(cur.toString());
            return;
        }

        int num = chs[level] - '0';
        for (int i = 0; i < dict[num].length(); ++i) {
            cur.append(dict[num].charAt(i));
            dfs(chs, dict, level + 1, cur, ans);
            cur.deleteCharAt(cur.length() - 1);
        }
    }
}