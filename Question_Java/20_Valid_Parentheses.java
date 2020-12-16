class Solution {
    public boolean isValid(String s) {
        Deque<Character> st = new ArrayDeque<>(s.length());
        for (char ch : s.toCharArray()) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else if (ch == ')') {
                if (st.isEmpty() || st.peek() != '(') return false;
                st.pop();
            } else if (ch == ']') {
                if (st.isEmpty() || st.peek() != '[') return false;
                st.pop();
            } else if (ch == '}') {
                if (st.isEmpty() || st.peek() != '{') return false;
                st.pop();
            }
        }
        return st.isEmpty();
    }
}