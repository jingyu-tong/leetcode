// brute force
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        HashMap<String, Integer> mem = new HashMap<>();
        for (String word : words) {
            Integer value = mem.getOrDefault(word, 0);
            mem.put(word, ++value);
        }

        int len = words[0].length();
        int n = words.length;
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i <= s.length() - n * len; ++i) {
            HashMap<String, Integer> tmem = (HashMap)mem.clone();
            int j = i;
            for ( ; j < i + n * len; j += len) {
                String sub_str = s.substring(j, j + len);
                if (!tmem.containsKey(sub_str) || tmem.get(sub_str) == 0) {
                    break;
                }
                int value = tmem.get(sub_str);
                tmem.put(sub_str, --value);
            }
            if (j == i + n * len) ans.add(i);
        }
        return ans;
    }
}

// sliding window
