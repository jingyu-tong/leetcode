class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode last = head;
        while (n-- != 0) {
            last = last.next;
        }

        ListNode cur = head;
        ListNode prev = cur;
        while (last != null) {
            last = last.next;
            prev = cur;
            cur = cur.next;
        }
        if (prev == cur) {
            head = head.next;
        } else {
            prev.next = cur.next;
        }
        return head;
    }
}