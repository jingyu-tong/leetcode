class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> mem = new HashMap<>();
        int ans = 0;
        int left = 0;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s.charAt(i);
            if (!mem.containsKey(ch) || mem.get(ch) < left) {
                ans = Math.max(ans, i - left + 1);
            } else {
                left = mem.get(ch) + 1;
            }
            mem.put(ch, i);
        }
        return ans;
    }
}