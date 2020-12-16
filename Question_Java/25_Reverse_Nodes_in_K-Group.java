class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;
        ListNode last = head;
        for (int i = 1; last != null; ++i) {
            if (i % k != 0) {
                last = last.next;
                continue;
            }
            prev = reverse(prev, last.next);
            last = prev.next;
        }
        return dummy.next;
    }
    private ListNode reverse(ListNode prev, ListNode end) {
        ListNode last = prev.next;
        ListNode cur = last.next;
        while (cur != end) {
            last.next = cur.next;
            cur.next = prev.next;
            prev.next = cur;
            cur = last.next;
        }
        return last;
    }
}