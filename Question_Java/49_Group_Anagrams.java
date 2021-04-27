class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> mem = new HashMap<>();
        for (String str : strs) {
            char[] chs = str.toCharArray();
            Arrays.sort(chs);
            String temp = new String(chs);
            List<String> l = mem.getOrDefault(temp, new ArrayList<String>());
            l.add(str);
            mem.put(temp, l);
        }
        return new ArrayList<List<String>>(mem.values());
    }
}