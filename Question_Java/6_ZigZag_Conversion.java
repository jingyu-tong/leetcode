class Solution {
    public String convert(String s, int numRows) {
        String[] strs = new String[numRows];
        Arrays.fill(strs, ""); // 用 range for loop 改不了，要特别注意，因为只是改变了引用本身指向的地址
        char[] chs = s.toCharArray();
        int i = 0;
        while (i < chs.length) {
            // order
            for (int j = 0; j < numRows && i < chs.length; ++j) {
                strs[j] += chs[i++];
            }
            // reverse
            for (int j = numRows - 2; j > 0 && i < chs.length; --j) {
                strs[j] += chs[i++];
            }
        }

        String ans = new String();
        for (String str : strs) {
            ans += str;
        }
        return ans;
    }
}