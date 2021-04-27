class Solution {
    private HashMap<Integer, Boolean> mem;
    private Integer length;

    public boolean isMatch(String s, String p) {
        mem = new HashMap<Integer, Boolean>();
        length = Math.max(s.length(), p.length()) + 1; // 降维成一维必须取最大
        return isMatch(s, p, 0, 0);
    }

    private boolean isMatch(String s, String p, int i, int j) {
        if (mem.containsKey(i * length + j))
            return mem.get(i * length + j);
        if (i == s.length() && j == p.length()) {
            mem.put(i * length + j, true);
            return true;
        }
        if (j == p.length()) {
            mem.put(i * length + j, false);
            return false;
        }
        if (i == s.length()) { // 必须 pattern 都为 *
            while (j < p.length()) {
                if (p.charAt(j) != '*') {
                    mem.put(i * length + j, false);
                    return false;
                }
                ++j;
            }
            mem.put(i * length + j, true);
            return true;
        }

        if (s.charAt(i) == p.charAt(j) || p.charAt(j) == '?') {
            boolean ans = isMatch(s, p, i + 1, j + 1);
            mem.put(i * length + j, ans);
            return ans;
        }

        if (p.charAt(j) == '*') {
            boolean ans = isMatch(s, p, i + 1, j) || isMatch(s, p, i, j + 1);
            mem.put(i * length + j, ans);
            return ans;
        }
        mem.put(i * length + j, false);
        return false;
    }
}